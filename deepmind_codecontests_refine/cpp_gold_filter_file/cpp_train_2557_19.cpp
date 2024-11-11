#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100000;
int fa[maxn];
int getfa(int x) { return (fa[x] < 0 ? x : fa[x] = getfa(fa[x])); }
int main() {
  memset(fa, -1, sizeof(fa));
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d%d", &p, &q);
    p = getfa(p);
    q = getfa(q);
    if (p == q) continue;
    if (fa[p] > fa[q]) swap(p, q);
    fa[p] += fa[q];
    fa[q] = p;
  }
  int l = 0, r = 2, p = 0;
  for (int i = 1; i <= n; i++)
    if (fa[i] < 0) {
      int j = -fa[i] < k ? -fa[i] : k;
      if (j == 1)
        l++;
      else
        r += j - 2;
      p++;
    }
  int ans = 0;
  if (l == 1)
    ans = 0;
  else if (k == 1)
    ans = p - 2;
  else if (l <= r)
    ans = 0;
  else
    ans = (l - r + 1) / 2;
  cout << ans << endl;
  return 0;
}
