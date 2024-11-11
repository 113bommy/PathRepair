#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
int k, head[maxn];
struct edge {
  int v, w, next;
} e[maxn];
void addedge(int u, int v, int w) {
  e[++k] = edge{v, w, head[u]};
  head[u] = k;
}
long long n, T, x[maxn], t[maxn], sum[maxn], num[maxn], ans[maxn], fas[maxn][2];
void update(int now, int L, int R, int pos, int val) {
  sum[now] += 1LL * pos * val;
  num[now] += val;
  if (L == R) return;
  long long mid = (L + R) >> 1;
  if (pos <= mid)
    update(now << 1, L, mid, pos, val);
  else
    update(now << 1 | 1, mid + 1, R, pos, val);
}
long long query(int now, int L, int R, long long T) {
  if (sum[now] <= T) return num[now];
  if (L == R) return min(T / L, num[now]);
  long long mid = (L + R) >> 1;
  if (sum[now << 1] <= T)
    return num[now << 1] + query(now << 1 | 1, mid + 1, R, T - sum[now << 1]);
  return query(now << 1, L, mid, T);
}
void dfs(int u, long long T) {
  if (T <= 0) return;
  update(1, 1, 1e6, t[u], x[u]);
  ans[u] = query(1, 1, 1e6, T);
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    dfs(v, T - 2LL * w);
    long long t = ans[v];
    if (t > fas[u][1]) swap(t, fas[u][1]);
    if (t > fas[u][0]) swap(t, fas[u][0]);
  }
  if (u == 1)
    ans[u] = max(ans[u], fas[u][1]);
  else
    ans[u] = max(ans[u], fas[u][0]);
  update(1, 1, 1e6, t[u], -x[u]);
}
int main() {
  int a, l;
  k = 0, memset(head, -1, sizeof head);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 2; i <= n; i++) {
    cin >> a >> l;
    addedge(a, i, l);
  }
  dfs(1, T);
  cout << ans[1] << endl;
  return 0;
}
