#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 1e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
int adj[N];
int deg[N], mk[N];
vector<int> V[N], G[N], R[N];
int la = -1;
int val[N];
int n, m, k;
set<pair<int, int> > st;
int Main() {
  st.clear();
  while (la > 0) {
    V[la].clear();
    la--;
  }
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) deg[i] = 0, G[i].clear(), R[i].clear();
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    mk[i] = 1;
    st.insert({deg[i], i});
  }
  while (!st.empty()) {
    pair<int, int> fr = *st.begin();
    if (fr.first >= k) {
      cout << "1 " << st.size() << '\n';
      for (auto X : st) cout << X.second << ' ';
      cout << '\n';
      return 0;
    }
    if (fr.first == k - 1) {
      la++;
      V[la].push_back(fr.second);
      for (auto nei : G[fr.second]) {
        if (mk[nei]) V[la].push_back(nei);
      }
    }
    st.erase(st.begin());
    mk[fr.second] = 0;
    for (auto nei : G[fr.second]) {
      if (mk[nei]) {
        st.erase({deg[nei], nei});
        deg[nei]--;
        st.insert({deg[nei], nei});
      }
    }
  }
  if ((k * (k - 1)) > m + m) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i <= la; i++) {
    val[i] = 1;
    for (auto nei : V[i]) R[nei].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (auto nei : G[i]) {
      adj[nei] = 1;
    }
    adj[i] = 1;
    for (int al : R[i]) {
      if (!val[al]) continue;
      for (auto el : V[al]) {
        if (adj[el] == 0) {
          val[al] = 0;
          break;
        }
      }
    }
    adj[i] = 0;
    for (auto nei : G[i]) {
      adj[nei] = 0;
    }
  }
  for (int i = 0; i <= la; i++) {
    if (val[i]) {
      cout << "2\n";
      for (auto x : V[i]) cout << x << ' ';
      cout << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
