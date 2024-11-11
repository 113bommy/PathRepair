#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a > 0) {
    if (a < b) swap(a, b);
    a %= b;
  }
  return b;
}
string big_sum(string a, string b) {
  if (a.size() < b.size()) swap(a, b);
  string ans = "";
  int sum, carry = 0;
  for (int i = 0; i < (int)b.size(); i++) {
    sum =
        a[(int)a.size() - 1 - i] - '0' + b[(int)b.size() - 1 - i] - '0' + carry;
    ans += (sum % 10) + '0';
    carry = sum / 10;
  }
  for (int i = (int)a.size() - b.size() - 1; i >= 0; i--) {
    sum = a[i] - '0' + carry;
    ans += (sum % 10) + '0';
    carry = sum / 10;
  }
  while (carry) {
    sum += (carry % 10) + '0';
    carry /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
string big_mult(string a, string b) {
  if (a == "0" || b == "0") return "0";
  string t[10], z = "", ans = "0";
  t[0] = "0";
  for (int i = 1; i < 10; i++) t[i] = big_sum(t[i - 1], a);
  for (int i = (int)b.size() - 1; i >= 0; i--) {
    ans = big_sum(ans, t[b[i] - '0'] + z);
    z += "0";
  }
  return ans;
}
string itos(long long m) {
  string ans = "";
  while (m > 0) {
    ans += (m % 10) + '0';
    m /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long g = w / (gcd(w, b)), Min = min(w, b), ans;
  string gs = "", bs = "", mul = "", INF = "";
  Min--;
  gs = itos(g);
  bs = itos(b);
  INF = itos(LLONG_MAX);
  mul = big_mult(gs, bs);
  if (mul.size() > 19 || (mul.size() == 19 && mul > INF)) {
    if (Min < t)
      ans = Min;
    else
      ans = t;
  } else {
    g *= b;
    if (t % g < Min)
      ans = (t / g) * (Min + 1) + t % g - 1;
    else
      ans = (t / g + 1) * (Min + 1) - 1;
  }
  long long red = gcd(ans, t);
  ans /= red;
  t /= red;
  cout << ans << "/" << t << endl;
  return 0;
}
