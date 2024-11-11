#include <bits/stdc++.h>
using namespace std;
int n, m;
long long h[100005], p[100005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d", &h[i]);
  sort(h, h + n);
  for (int i = 0; i < m; i++) scanf("%I64d", &p[i]);
  sort(p, p + m);
  long long L = 0, R = 20000000000LL, C;
  while (L < R) {
    C = (L + R) / 2;
    int k = 0;
    for (int i = 0; i < n && k < m; i++) {
      if (p[k] < h[i]) {
        if (h[i] - p[k] > C) break;
        long long reserv = max(C - (h[i] - p[k]) * 2, (C - (h[i] - p[k])) / 2);
        while (k < m && h[i] + reserv >= p[k]) k++;
      } else {
        while (k < m && h[i] + C >= p[k]) k++;
      }
    }
    if (k == m)
      R = C;
    else
      L = C + 1;
  }
  printf("%I64d\n", R);
  return 0;
}
