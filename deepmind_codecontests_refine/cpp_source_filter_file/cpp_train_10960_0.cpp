#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[1000005], x, y, cl[1000005], id, fa[1000005], fl[1000005],
    cnt, tot, ans;
vector<long long> v[1000005];
struct node {
  long long x_id, y_id, x, y;
  bool operator<(const node& w) const {
    return x_id == w.x_id ? y_id < w.y_id : x_id < w.x_id;
  }
} e[1000005];
inline long long find(long long x) {
  return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void dfs(long long x, long long col) {
  cl[x] = col;
  for (long long i = 0; i < v[x].size(); i++) {
    long long h = v[x][i];
    if (cl[h] == cl[x]) fl[a[x]] = 1;
    if (!cl[h]) dfs(h, col ^ 1);
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    if (a[x] == a[y])
      v[x].push_back(y), v[y].push_back(x);
    else
      e[++cnt] = (node){min(a[x], a[y]), max(a[x], a[y]), x, y};
  }
  sort(e + 1, e + cnt + 1);
  for (long long i = 1; i <= n; i++)
    if (!cl[i]) {
      id += 2;
      dfs(i, id);
    }
  for (long long i = 1; i <= k; i++)
    if (fl[i]) tot++;
  for (long long i = 1; i <= tot; i++) ans += (k - i);
  for (long long i = 1, j; i <= cnt; i = j + 1) {
    j = i;
    long long ok = 0;
    while (j < m && e[j + 1].x_id == e[i].x_id && e[j + 1].y_id == e[i].y_id)
      j++;
    if (fl[e[i].x] || fl[e[i].y]) continue;
    for (long long l = i; l <= j; l++) {
      fa[cl[e[l].x]] = cl[e[l].x];
      fa[cl[e[l].y]] = cl[e[l].y];
      fa[cl[e[l].x] ^ 1] = cl[e[l].x] ^ 1;
      fa[cl[e[l].y] ^ 1] = cl[e[l].y] ^ 1;
    }
    for (long long l = i; l <= j; l++) {
      fa[find(cl[e[l].x])] = find(cl[e[l].y] ^ 1);
      fa[find(cl[e[l].x] ^ 1)] = find(cl[e[l].y]);
    }
    for (long long l = i; l <= j; l++) {
      if (find(cl[e[l].x]) == find(cl[e[l].x] ^ 1)) ok = 1;
      if (find(cl[e[l].y]) == find(cl[e[l].y] ^ 1)) ok = 1;
    }
    ans += ok;
  }
  printf("%lld", k * (k - 1) / 2 - ans);
}
