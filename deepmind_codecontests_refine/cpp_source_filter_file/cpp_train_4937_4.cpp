#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
inline long long bpow(long long t, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * t) % mod;
    t = (t * t) % mod, n >>= 1;
  }
  return ans;
}
const int maxL = 18;
vector<int> vec[MAX_N];
int lca[MAX_N][maxL];
int h[MAX_N];
int get_a(int v, int k) {
  for (int i = 0; i < maxL; i++)
    if ((k >> i) & 1) v = lca[v][i];
  return v;
}
int LCA(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  v = get_a(v, h[v] - h[u]);
  if (v == u) return v;
  for (int i = maxL - 1; i >= 0; i--)
    if (lca[v][i] != lca[u][i]) v = lca[v][i], u = lca[u][i];
  return lca[v][0];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(0);
  int q;
  cin >> q;
  lca[2][0] = lca[3][0] = lca[4][0] = 0;
  h[2] = h[3] = h[4] = 1;
  int ans = 2, st = 2, en = 3, n = 4;
  while (q--) {
    int v;
    cin >> v;
    h[n + 1] = h[n + 2] = h[v] + 1;
    lca[n + 1][0] = lca[n + 2][0] = v;
    for (int i = 1; i < maxL; i++)
      lca[n + 1][i] = lca[lca[n + 1][i - 1]][i - 1],
              lca[n + 2][i] = lca[lca[n + 2][i - 1]][i - 1];
    int top1 = LCA(n + 1, st), top2 = LCA(n + 1, en);
    int d1 = h[n + 1] + h[st] - 2 * h[top1],
        d2 = h[n + 1] + h[en] - 2 * h[top2];
    if (d1 >= d2 && d1 > ans)
      ans = d1, en = n + 1;
    else if (d2 > d1 && d2 > ans)
      ans = d2, st = n + 1;
    cout << ans << '\n';
    n += 2;
  }
}
