#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 10, K = 22;
int n, m, k, p[K], lef[N], rig[N];
char s[K], t[K];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s, t);
  int cnts = 0, cntt = 0;
  for (int i = 0; i < k; ++i) cnts += s[i] - '0', cntt += t[i] - '0';
  for (int i = 1; i <= k; ++i) p[i] = i;
  for (int i = 0; i < 1 << k; ++i) lef[i] = N, rig[i] = -1;
  for (int i = 1, x, y, j, st; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    for (j = 0, st = 0; j < k; ++j) st |= (s[j] - '0') << p[j + 1] - 1;
    lef[st] = min(lef[st], i - 1);
    swap(p[x], p[y]);
    for (j = 0, st = 0; j < k; ++j) st |= (t[j] - '0') << p[j + 1] - 1;
    rig[st] = max(rig[st], i);
  }
  for (int d = 1; d < (1 << k); d <<= 1)
    for (int i = 0; i < (1 << k); i += d + d)
      for (int j = 0; j < d; ++j) {
        lef[i + j] = min(lef[i + j], lef[i + j + d]);
        rig[i + j] = max(rig[i + j], rig[i + j + d]);
      }
  int ansc = -1, ansl, ansr;
  for (int i = 0; i < 1 << k; ++i)
    if (rig[i] - lef[i] >= m)
      if (__builtin_popcount(i) > ansc) {
        ansc = __builtin_popcount(i);
        ansl = lef[i] + 1;
        ansr = rig[i];
      }
  printf("%d\n%d %d\n", k + 2 * ansc - cnts - cntt, ansl, ansr);
  return 0;
}
