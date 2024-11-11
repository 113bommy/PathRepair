#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int fa[maxn], cnt[maxn];
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
int main() {
  int n, m, k, a, b;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    fa[find(a)] = find(fa[b]);
  }
  for (int i = 1; i <= n; i++) cnt[fa[i]]++;
  long long ans = 1;
  int scc = 0;
  for (int i = 1; i <= n; i++)
    if (fa[i] == i) {
      ans = ans * cnt[i] % k;
      scc++;
    }
  if (scc == 1) ans /= cnt[find(1)];
  for (int i = 0; i < scc - 2; i++) ans = ans * n % k;
  printf("%d\n", ans);
  return 0;
}
