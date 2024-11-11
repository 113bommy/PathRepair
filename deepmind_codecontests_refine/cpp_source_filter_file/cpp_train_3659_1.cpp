#include <bits/stdc++.h>
using ll = long long;
const int D = 21;
int changer(ll a) {
  ll res = 0;
  while (a > 0) {
    if (a % 10 > 0) res++;
    a /= 10;
  }
  return res;
}
void deformulate(ll value, ll dp[]) {
  int i = 1;
  while (value > 0) {
    dp[i] = value - value / 10;
    value /= 10;
    i++;
  }
  for (i = i - 1; i >= 0; i--) dp[i] += dp[i + 1];
}
ll dpH[D], dpM[D], min_dpM[D], max_dpM[D], min_dpH[D], max_dpH[D];
int main() {
  int k, i;
  ll h, m, h1, m1, h2, m2;
  ll minutes_transform, H_transforms, H_full_cycles, res = 0;
  scanf("%lld %lld %d", &h, &m, &k);
  scanf("%lld %lld %lld %lld", &h1, &m1, &h2, &m2);
  deformulate(m - 1, dpM);
  deformulate(m1, min_dpM);
  deformulate(m2, max_dpM);
  deformulate(h1, min_dpH);
  deformulate(h2, max_dpH);
  if (h1 == h2 && m1 <= m2) {
    for (i = 0; i < D; i++) dpH[i] = 0;
  } else if (h1 < h2) {
    for (i = 0; i < D; i++) dpH[i] = max_dpH[i] - min_dpH[i];
  } else {
    deformulate(h - 1, dpH);
    for (i = 0; i < D; i++) dpH[i] -= min_dpH[i];
    for (i = 0; i < D; i++) dpH[i] += max_dpH[i];
  }
  minutes_transform = changer(m - 1);
  if (h1 == h2 && m1 <= m2)
    H_transforms = 0, H_full_cycles = 0;
  else {
    H_transforms = h2 - h1;
    if (H_transforms < 0) H_transforms += h;
    H_full_cycles = H_transforms - 1;
  }
  res = dpM[k] * H_full_cycles;
  res += dpH[(((k - minutes_transform) > (0)) ? (k - minutes_transform) : (0))];
  if (h1 == h2 && m1 <= m2)
    res += max_dpM[k] - min_dpM[k];
  else {
    res += dpM[k] - min_dpM[k];
    res += max_dpM[k];
  }
  if (changer(h - 1) + minutes_transform >= k &&
      (h1 > h2 || (h1 == h2 && m2 < m1)))
    res++;
  printf("%lld\n", res);
  return 0;
}
