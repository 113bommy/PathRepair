#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
int a[maxn], b[maxn], sm[maxn], f[maxn], g[maxn], l[maxn], r[maxn], GA[maxn];
int N, M, o, tc, maxc, len;
int main() {
  scanf("%d %d", &N, &M);
  int BA = N;
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= M; i++) scanf("%d", &b[i]);
  memset(sm, 0, sizeof(sm));
  for (int i = 1; i <= M; i++) sm[b[i]] = 1;
  for (int i = 1; i < maxn; i++) sm[i] = sm[i - 1] + sm[i];
  sort(a + 1, a + N + 1);
  sort(b + 1, b + M + 1);
  o = 1, l[1] = 1;
  for (int i = 2; i <= N; i++)
    if (a[i] != a[i - 1] + 1) {
      ++o, r[o - 1] = i - 1, l[o] = i;
    }
  r[o] = N;
  for (int i = 1; i <= o; i++)
    for (int j = l[i]; j <= r[i]; j++) GA[j] = i;
  N = o;
  for (int i = 0; i <= N; i++) f[i] = g[i] = -1;
  f[0] = g[0] = 0;
  for (int i = 1; i <= N; i++) {
    f[i] = max(f[i], g[i - 1] + sm[a[r[i]]] - sm[a[l[i]] - 1]);
    maxc = -1;
    for (int j = 1; j <= M; j++) {
      if ((b[j] < a[l[i]]) && (a[l[i]] - b[j] < l[i])) {
        tc = GA[l[i] - a[l[i]] + b[j]];
        len = r[i] - l[tc] + 1;
        maxc = max(maxc, g[tc - 1] + sm[a[r[i]]] - sm[a[r[i]] - len]);
      }
    }
    if (maxc >= 0) f[i] = max(f[i], maxc);
    f[i] = max(f[i], sm[a[r[i]]] - sm[a[r[i]] - r[i]]);
    g[i] = max(g[i], f[i]);
    for (int j = 1; j <= M; j++)
      if ((b[j] > a[r[i]]) && (b[j] - a[r[i]] + r[i] <= BA)) {
        tc = GA[b[j] - a[r[i]] + r[i]];
        len = r[tc] - r[i];
        g[tc] = max(g[tc], f[i] + sm[a[r[i]] + len] - sm[a[r[i]]]);
      }
    len = r[N] - r[i];
    g[N] = max(g[N], f[i] + sm[a[r[i]] + len] - sm[a[r[i]]]);
  }
  printf("%d\n", g[N]);
  return 0;
}
