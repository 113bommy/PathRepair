#include <bits/stdc++.h>
using namespace std;
const int MN = 1000010;
const long long INF = 1000200013;
const double eps = 1e-12;
long long n, m, ans = 0;
int ls, lc, u[MN], d[MN][26];
char s[MN], c[MN];
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  scanf("%lld%lld %s %s", &n, &m, s, c);
  ls = strlen(s);
  lc = strlen(c);
  int g = gcd(ls, lc);
  long long l = ls * 1LL * lc / g;
  for (int i = 0; i < ls; i++) {
    d[i % g][s[i] - 97]++;
  }
  for (int i = 0; i < lc; i++) {
    ans += d[i % g][c[i] - 97];
  }
  ans = l - ans;
  printf("%lld\n", ans * n * ls / l);
  return 0;
}
