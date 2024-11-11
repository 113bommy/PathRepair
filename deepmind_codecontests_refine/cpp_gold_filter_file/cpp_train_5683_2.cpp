#include <bits/stdc++.h>
using namespace std;
using llong = long long;
char buf[222222];
int getint() {
  int n;
  scanf("%d", &n);
  return n;
}
long long qpow(long long a, long long b, long long c) {
  long long p = 1;
  while (b) {
    if (b & 1) p = p * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return p;
}
int main() {
  scanf("%s", buf);
  string s(buf);
  llong m = getint();
  llong r = 0;
  for (int i = 0; i < s.size(); i++) {
    r = r * 10 + (s[i] - '0');
    r %= m;
  }
  llong ans = r;
  for (int i = 0; i + 1 < s.size(); i++) {
    r += m - (s[i] - '0') * qpow(10, s.size() - 1, m) % m;
    r *= 10;
    r += s[i] - '0';
    r %= m;
    if (s[i + 1] != '0') {
      ans = min(ans, r);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
