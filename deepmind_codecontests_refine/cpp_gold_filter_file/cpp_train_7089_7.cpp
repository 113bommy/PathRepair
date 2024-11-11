#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long s[maxn];
int f[maxn], F[maxn], p[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &s[i]);
  }
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = n; i > 1; --i) {
    s[p[i]] += s[i];
  }
  for (int i = n; i; --i) {
    long long t = s[1] / gcd(s[1], s[i]);
    if (t <= n) {
      ++f[t];
    }
  }
  for (int i = n; i; --i) {
    for (int j = i; (j += i) <= n;) {
      f[j] += f[i];
    }
  }
  int ans = 0;
  F[1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (f[i] == i) {
      ans += F[i];
      for (int j = i * 2; j <= n; j += i) {
        F[j] += F[i];
      }
    }
  }
  printf("%d", ans);
  return 0;
}
