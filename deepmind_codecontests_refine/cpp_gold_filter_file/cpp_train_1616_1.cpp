#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return abs(a - b);
  long long res = a % b;
  while (res) {
    a = b;
    b = res;
    res = a % b;
  }
  return b;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long numberofdiviser(long long a) {
  long long ans = 0;
  long long i;
  for (i = 1; i * i < a; i++) {
    if (a % i == 0) ans += 2;
  }
  if (i * i == a) ans++;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s, s1 = "1";
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    if (s == "0") return cout << 0 << endl, 0;
    string s2(s.size(), '0');
    s2[0] = '1';
    if (s != s2)
      s1 = s;
    else {
      sum += s.size() - 1;
    }
  }
  cout << s1;
  while (sum--) cout << "0";
}
