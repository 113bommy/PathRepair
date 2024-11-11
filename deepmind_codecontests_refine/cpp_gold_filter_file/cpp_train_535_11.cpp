#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int N = 50;
int n, m, k, c, d, mxt;
const int fN = (N * 3 + 1) * N + 2;
int s, t, fn;
vector<int> e[fN], to, fw, co;
void adde(int u, int v, int w, int c) {
  e[u].push_back(int((to).size())), to.push_back(v), fw.push_back(w),
      co.push_back(+c);
  e[v].push_back(int((to).size())), to.push_back(u), fw.push_back(0),
      co.push_back(-c);
}
int dep[fN], pre[fN];
bool vis[fN];
bool spfa() {
  fill(dep, dep + fn, iinf), fill(pre, pre + fn, -1),
      fill(vis, vis + fn, false);
  queue<int> q;
  q.push(s), vis[s] = true, dep[s] = 0;
  while (int((q).size())) {
    int u = q.front();
    q.pop(), vis[u] = false;
    for (int v : e[u])
      if (fw[v] && dep[to[v]] > dep[u] + co[v])
        dep[to[v]] = dep[u] + co[v], pre[to[v]] = v,
        (!vis[to[v]]) && (q.push(to[v]), vis[to[v]] = true);
  }
  return dep[t] < iinf;
}
pair<int, int> mcmf() {
  pair<int, int> res(0, 0);
  while (spfa()) {
    int f = iinf;
    for (int u = t; u != s; u = to[pre[u] ^ 1]) f = min(f, fw[pre[u]]);
    for (int u = t; u != s; u = to[pre[u] ^ 1])
      fw[pre[u]] -= f, fw[pre[u] ^ 1] += f;
    res.first += f, res.second += dep[t] * f;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> c >> d, mxt = N * 3 + 1;
  fn = (t = (s = n * mxt) + 1) + 1;
  for (int i = (0), iE = (k); i < iE; i++) {
    int u;
    cin >> u, --u, adde(s, u, 1, 0);
  }
  while (m--) {
    int u, v;
    cin >> u >> v, --u, --v;
    for (int i = (0), iE = (mxt - 1); i < iE; i++)
      for (int p = (1), pE = (k + 1); p < pE; p++)
        adde(i * n + u, (i + 1) * n + v, 1, 2 * d * p - d),
            adde(i * n + v, (i + 1) * n + u, 1, 2 * d * p - d);
  }
  for (int u = (0), uE = (n); u < uE; u++)
    for (int i = (0), iE = (mxt - 1); i < iE; i++)
      adde(i * n + u, (i + 1) * n + u, k, 0);
  for (int i = (0), iE = (mxt); i < iE; i++) adde(i * n, t, k, i * c);
  pair<int, int> ans = mcmf();
  assert(ans.first == k);
  cout << ans.second << '\n';
  return 0;
}
