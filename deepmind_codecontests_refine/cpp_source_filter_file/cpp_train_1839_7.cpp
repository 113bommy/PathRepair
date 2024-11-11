#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng((unsigned long long)new char);
const double eps = 1e-7;
const int maxn = 5e5 + 10;
const long long INF = 1e18;
const int mod = 1e9 + 7;
int n, m;
int root[maxn], son[maxn << 2][2];
int cnt = 0;
int v[maxn << 2];
void update(int& o, int l, int r, int p, int x) {
  if (!o) o = ++cnt;
  v[o] = max(v[o], x);
  if (l == r) return;
  if (x <= ((l + r) >> 1))
    update(son[o][0], l, ((l + r) >> 1), p, x);
  else
    update(son[o][1], ((l + r) >> 1) + 1, r, p, x);
}
int query(int o, int l, int r, int L, int R) {
  if (!o) return 0;
  if (l >= L && r <= R) return v[o];
  int ans = 0;
  if (L <= ((l + r) >> 1))
    ans = max(ans, query(son[o][0], l, ((l + r) >> 1), L, R));
  if (R >= ((l + r) >> 1))
    ans = max(ans, query(son[o][1], ((l + r) >> 1) + 1, r, L, R));
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int ans = 0;
  for (int t = (0); t < (m); ++t) {
    int u, v, w;
    cin >> u >> v >> w;
    ++w;
    int x = query(root[u], 1, 100000, 1, w - 1) + 1;
    ans = max(ans, x);
    update(root[v], 1, 100001, w, x);
  }
  cout << ans;
}
