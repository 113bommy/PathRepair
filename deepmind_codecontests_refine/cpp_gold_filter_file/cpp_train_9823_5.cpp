#include <bits/stdc++.h>
const int maxn = 63;
int tot;
int a[maxn];
int p[maxn];
int mu[maxn];
long long bin[maxn];
bool vis[maxn];
void Init();
long long HAHA(long long);
long long Calc(int);
int main() {
  long long l, r;
  Init();
  std::cin >> l >> r;
  std::cout << HAHA(r) - HAHA(l - 1) << "\n";
  return 0;
}
inline void Init() {
  mu[1] = bin[0] = 1;
  for (int i = 1; i < maxn; ++i) bin[i] = bin[i - 1] << 1;
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) p[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && i * p[j] < maxn; ++j) {
      vis[i * p[j]] = true;
      if (i % p[j])
        mu[i * p[j]] = -mu[i];
      else {
        mu[i * p[j]] = 0;
        break;
      }
    }
  }
  for (int i = 1; i < maxn; ++i) mu[i] = -mu[i];
}
inline long long HAHA(long long x) {
  if (!x) return 0;
  int n = 0;
  long long ans = 0, xx = x;
  while (xx) a[++n] = xx & 1, xx >>= 1;
  std::reverse(a + 1, a + n + 1);
  for (int i = 2; i < n; ++i) ans += Calc(i);
  for (int k = 2; k <= n; ++k)
    if (n % k == 0 && mu[k]) {
      int len = n / k;
      long long now = (x >> (len * (k - 1))) & (bin[len] - 1);
      for (int i = 2; i <= k; ++i) {
        long long temp = (x >> (len * (k - i))) & (bin[len] - 1);
        if (temp > now) break;
        if (temp < now) {
          --now;
          break;
        }
      }
      ans += (now - bin[len - 1] + 1) * mu[k];
    }
  return ans;
}
inline long long Calc(int n) {
  long long ans = 0;
  for (int k = 2; k <= n; ++k)
    if (n % k == 0 && mu[k]) ans += mu[k] * bin[n / k - 1];
  return ans;
}
