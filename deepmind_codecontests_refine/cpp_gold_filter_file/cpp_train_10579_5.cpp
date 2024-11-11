#include <bits/stdc++.h>
int rd() {
  int k = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return k;
}
const int N = 10000001;
int Max(int x, int y) { return x > y ? x : y; }
int n, P[670001], s, phi[N], mp[N], c[N];
bool p[N];
long long ans;
int Q(int l, int r) { return r < l ? 0 : c[r] - c[l]; }
int main() {
  n = rd(), phi[1] = 1, ans = (long long)(n - 1) * (n - 2) / 2;
  for (int i = 2; i <= n; ++i) {
    if (!p[i]) ++c[i], P[++s] = mp[i] = i, phi[i] = i - 1;
    for (int j = 1, k; j <= s && (k = i * P[j]) <= n; ++j) {
      p[k] = 1, ++c[mp[k] = P[j]];
      if (i % P[j])
        phi[k] = phi[i] * (P[j] - 1);
      else {
        phi[k] = phi[i] * P[j];
        break;
      }
    }
  }
  for (int i = 2; i <= n; ++i) c[i] += c[i - 1], ans += phi[i] - 1;
  for (int i = 1; i <= s; ++i)
    ans += (long long)(Q(Max(P[i], n / P[i]), Max(p[i], n / 2)) -
                       2 * Q(Max(P[i], n / 2), n)) *
           (c[P[i]] - c[P[i] - 1]);
  printf("%lld\n", ans);
  return 0;
}
