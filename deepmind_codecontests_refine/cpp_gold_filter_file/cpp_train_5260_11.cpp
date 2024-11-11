#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
long long inv(long long x) { return expo(x, mod - 2); }
bool isPal(string ss) {
  int len = ss.length();
  for (int i = 0; i < len / 2; i++) {
    int comp = len - i - 1;
    if (ss[i] != ss[comp]) return false;
  }
  return true;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 100011;
int suf[M];
int main() {
  int n;
  long long k;
  scanf("%d", &(n));
  scanf("%lld", &(k));
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    int a = (str[i] - 'a');
    int b = ('z' - str[i]);
    suf[i] = max(a, b);
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] += suf[i + 1];
  }
  if (k > suf[0]) {
    cout << "-1";
    return 0;
  }
  vector<char> vec;
  for (int i = 0; i < n; i++) {
    if (suf[i + 1] >= k) {
      vec.push_back(str[i]);
      continue;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int here = abs(str[i] - ch);
      long long tem = here + suf[i + 1];
      if (tem == k) {
        vec.push_back(ch);
        k -= here;
        break;
      }
    }
  }
  for (int i = 0; i < vec.size(); i++) {
    printf("%c", vec[i]);
  }
}
