#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], bin[100010];
vector<pair<int, int> > q[100010];
int s[100010], part[100010], sum[100010], sp[100010];
int last[100010], fa[100010];
int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
int calc(int x, int y) {
  return (s[x] - 1ll * s[y + 1] * bin[y - x + 1] % 1000000007 + 1000000007) %
         1000000007;
}
void merge(int x, int y) {
  if ((x - last[x] > 31 && part[y] > 0) ||
      (part[x] + ((1ll * part[y]) << (x - last[x])) > 1000000007))
    part[y] = 1000000007;
  else
    part[y] = part[x] + (part[y] << (x - last[x]));
  fa[x] = y;
  last[y] = last[x];
}
int ans[100010];
int main() {
  scanf("%d %d", &n, &m);
  bin[0] = 1;
  for (int i = 1; i <= n; i++) bin[i] = 2ll * bin[i - 1] % 1000000007;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), fa[i] = i;
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d %d", &x, &y);
    q[y].push_back(make_pair(x, i));
  }
  for (int i = n; i >= 1; i--)
    s[i] = (2ll * s[i + 1] + a[i] + 1000000007) % 1000000007;
  for (int i = 1; i <= n; i++) {
    last[i] = i - 1;
    part[i] = a[i];
    while (last[i] && part[i] >= 0) merge(last[i], i);
    sum[i] = (sum[last[i]] + 2ll * calc(last[i] + 1, i)) % 1000000007;
    for (pair<int, int> j : q[i]) {
      int p = findfa(j.first);
      ans[j.second] =
          (calc(j.first, p) + (sum[i] - sum[p] + 1000000007) % 1000000007) %
          1000000007;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
