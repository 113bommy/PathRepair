#include <bits/stdc++.h>
template <typename A, typename B>
inline void amax(A &x, B y) {
  if (x < y) x = y;
}
template <typename A, typename B>
inline void amin(A &x, B y) {
  if (!(x < y)) x = y;
}
using namespace std;
int n;
long long L[9], R[9];
double ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld %lld", L + i, R + i);
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    long long mn = 10000 + 1;
    long long mx = -1;
    double r = 1.0;
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) != 0) amin(mn, R[j]), amax(mx, L[j]), cnt++;
    if (mn < mx || cnt < 2) continue;
    for (long long j = mx; j <= mn; j++) {
      r = 1.0;
      for (int u = 0; u < n; u++)
        if ((i & (1 << u)) == 0) {
          if (L[u] > j)
            r = 0.0;
          else
            r *= (min(R[u], j - 1LL) - L[u] + 1LL) * 1.0;
        }
      ans += r * j;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    long long mn = 10000 + 1;
    long long mx = -1;
    double r = 1.0;
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) != 0) amin(mn, R[j]), amax(mx, L[j]), cnt++;
    if (mn < mx || cnt < 2) continue;
    for (int o = 0; o < n; o++)
      if ((i & (1 << o)) == 0)
        for (long long j = mx; j <= mn; j++) {
          r = 1.0;
          for (int u = 0; u < n; u++)
            if ((i & (1 << u)) == 0 && u != o) {
              if (L[u] > j)
                r = 0.0;
              else
                r *= (min(R[u], j - 1LL) - L[u] + 1LL) * 1.0;
            }
          if (R[o] <= j)
            r = 0.0;
          else
            r *= (R[o] - max(j + 1, L[o]) + 1LL) * 1.0;
          ans += r * j;
        }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (long long t = L[i]; t <= R[i]; t++)
        if (i != j) {
          double r = 1.0;
          for (int u = 0; u < n; u++)
            if (u != i && u != j) {
              if (L[u] >= t)
                r = 0.0;
              else
                r *= (min(R[u], t - 1) - L[u] + 1LL) * 1.0;
            }
          if (t > R[j]) r = 0.0;
          r *= (R[j] - max(L[j], t + 1) + 1LL) * 1.0;
          r *= t * 1.0;
          ans += r;
        }
  for (int i = 0; i < n; i++) ans /= (R[i] - L[i] + 1LL) * 1.0;
  printf("%.12lf", ans);
}
