#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<int> ans;
map<int, int> mp;
void dfsUtil(int u, vector<pair<int, int>> adj[], int vis[]) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (!vis[v.first]) {
      if (mp[u] != 1 && mp[v.first] != 1) {
        mp[u] = 1, mp[v.first] = 1;
        ans.push_back(v.second);
      }
      dfsUtil(v.first, adj, vis);
    }
  }
}
void dfs(vector<pair<int, int>> adj[], int n) {
  int vis[n];
  for (int i = 0; i < n; i++) vis[i] = 0;
  ;
  ans.clear();
  mp.clear();
  for (int i = 0; i < n; i++) mp[i] = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfsUtil(i, adj, vis);
    }
  }
  vector<int> st;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    if (itr->second == 0) st.push_back(itr->first);
  }
  if (ans.size() >= n / 3) {
    cout << "Matching\n";
    int cnt = 0;
    for (int i = 0; i < ans.size() && cnt < n / 3; i++) {
      cout << ans[i] << " ";
      cnt++;
    }
    cout << endl;
  } else if (st.size() >= n / 3) {
    cout << "IndSet\n";
    int cnt = 0;
    for (int i = 0; i < st.size() && cnt < n / 3; i++) {
      cout << st[i] + 1 << " ";
      cnt++;
    }
    cout << endl;
  } else {
    cout << "Impossible\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    int n, m;
    cin >> n >> m;
    n *= 3;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(make_pair(v, i + 1));
      adj[v].push_back(make_pair(u, i + 1));
    }
    dfs(adj, n);
  }
}
