#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<int> graf[300005];
int cnt[300005];
pair<int, int> kveri[300005];
bool vis[300005];
int cale[300005];
int disc[300005];
int out[300005];
int t;
void dfs(int u) {
  vis[u] = true;
  disc[u] = t;
  for (int c : graf[u]) {
    if (vis[c]) continue;
    t++;
    cale[c] = u;
    dfs(c);
  }
  out[u] = t;
}
bool anc(int x, int y) { return disc[x] <= disc[y] && out[y] <= out[x]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int(i) = (1); (i) <= (m); ++(i)) {
    int u, v;
    cin >> u >> v;
    graf[u].push_back(v);
    graf[v].push_back(u);
  }
  dfs(1);
  cin >> q;
  for (int(i) = (1); (i) <= (q); ++(i)) {
    cin >> kveri[i].first >> kveri[i].second;
    cnt[kveri[i].first]++;
    cnt[kveri[i].second]++;
  }
  int s = 0;
  for (int(i) = (1); (i) <= (n); ++(i)) s += (cnt[i] & 1);
  if (s) {
    cout << "NO\n" << s / 2;
    return 0;
  }
  cout << "YES\n";
  for (int(i) = (1); (i) <= (q); ++(i)) {
    int a = kveri[i].first;
    int b = kveri[i].second;
    vector<int> r;
    while (!anc(a, b)) {
      r.push_back(a);
      a = cale[a];
    }
    r.push_back(a);
    vector<int> l;
    while (b != a) {
      l.push_back(b);
      b = cale[b];
    }
    reverse(l.begin(), l.end());
    vector<int> ans;
    for (int c : r) ans.push_back(c);
    for (int c : l) ans.push_back(c);
    cout << ans.size() << "\n";
    for (int c : ans) cout << c << " ";
    cout << "\n";
  }
  return 0;
}
