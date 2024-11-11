#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int p[maxn], a[maxn], b[maxn], n, m, u, v, ans, res;
void solve() {
  int cnt = 0, val = 0;
  memcpy(b, a, sizeof a);
  for (register int i = (1); i <= (n); i++) {
    u = p[i];
    v = 0;
    for (register int j = (0); j <= (n - 1); j++)
      if ((b[u] >> j & 1) && (b[j] & b[u]) != b[u]) {
        b[j] |= b[u];
        v = 1;
      }
    if (v) cnt++, val |= 1 << u;
    if (cnt >= ans) return;
  }
  for (register int i = (0); i <= (n - 1); i++)
    if (b[i] < (1 << n) - 1) return;
  ans = cnt;
  res = val;
}
int main() {
  srand(time(NULL));
  scanf("%d%d", &n, &m);
  for (register int i = (1); i <= (m); i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    a[u] |= 1 << v;
    a[v] |= 1 << u;
  }
  for (register int i = (0); i <= (n - 1); i++) a[i] |= 1 << i, p[i + 1] = i;
  ans = n - 1;
  while (1) {
    random_shuffle(p + 1, p + n + 1);
    solve();
    if (clock() > 0.06 * CLOCKS_PER_SEC) break;
  }
  printf("%d\n", ans);
  for (register int i = (0); i <= (n - 1); i++)
    if (res >> i & 1) printf("%d ", i + 1);
  return 0;
}
