#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
const int lim = 1 << 19;
int n, x, cnt[maxn], fa[maxn], vis[maxn];
long long ans;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void join(long long w, int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y)
    fa[x] = y, ans += w * (vis[x] ? 1 : cnt[x] + vis[y] ? 1 : cnt[y] - 1);
  vis[x] = vis[y] = 1;
}
int main() {
  for (auto i = (1); i <= (lim); ++i) fa[i] = i;
  scanf("%d", &n);
  cnt[0]++;
  for (auto i = (1); i <= (n); ++i) scanf("%d", &x), cnt[x]++, ans -= x;
  for (auto w = (lim); w >= (0); --w)
    for (int u = w; u; u = (u - 1) & w) {
      int v = w ^ u;
      if (cnt[u] && cnt[v]) join(w, u, v);
    }
  printf("%lld\n", ans);
}
