#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
bool n_p[101101];
int s_p, p[101101], phi[101101];
std::vector<int> fact[101101];
inline void init(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!n_p[i]) p[++s_p] = i, phi[i] = i - 1;
    for (int j = 1; j <= s_p && p[j] <= n / i; j++) {
      n_p[i * p[j]] = 1;
      if (!(i % p[j])) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) fact[j].push_back(i);
}
int n, a[101101], cnt[101101];
int main() {
  n = read<int>();
  for (int i = 1; i <= n; i++) a[i] = read<int>();
  init(1e5);
  long long ans = 0;
  for (int d = 1; d <= n; d++) {
    long long s = 0;
    for (int i = d; i <= n; i += d)
      for (auto x : fact[a[i]]) {
        (s += 1ll * (2 * cnt[x] + 1) * phi[x]) %= 1000000007;
        cnt[x]++;
      }
    (ans += phi[d] * s) %= 1000000007;
    for (int i = d; i <= n; i += d)
      for (auto x : fact[a[i]]) cnt[x] = 0;
  }
  printf("%lld\n", ans);
  return 0;
}
