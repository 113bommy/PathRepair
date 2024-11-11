#include <bits/stdc++.h>
using namespace std;
bool helper(vector<vector<long long>>& graph, long long start,
            vector<long long>& st, vector<bool>& hasvisit,
            vector<bool>& hasvisit2) {
  hasvisit[start] = hasvisit2[start] = true;
  for (auto x : graph[start]) {
    if (hasvisit2[x] == true) return false;
    if (hasvisit[x] == false)
      if (helper(graph, x, st, hasvisit, hasvisit2) == false) return false;
  }
  st.push_back(start);
  hasvisit2[start] = false;
  return true;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> graph(n + 1);
  vector<pair<long long, long long>> undir;
  for (long long i = 0; i < m; i++) {
    long long t, a, b;
    cin >> t >> a >> b;
    if (t) {
      graph[a].push_back(b);
    } else {
      undir.push_back({a, b});
    }
  }
  vector<bool> hasvisit(n + 1, false);
  vector<bool> hasvisit2(n + 1, false);
  vector<long long> st;
  for (long long i = 1; i < graph.size(); i++) {
    if (hasvisit[i] == false &&
        helper(graph, i, st, hasvisit, hasvisit2) == false) {
      cout << "NO\n";
      return;
    }
  }
  unordered_map<long long, long long> mp;
  for (long long i = 0; i < st.size(); i++) {
    mp[st[i]] = i;
  }
  for (long long i = 0; i < undir.size(); i++) {
    long long a = undir[i].first;
    long long b = undir[i].second;
    if (mp[a] > mp[b]) {
      graph[a].push_back(b);
    } else {
      graph[b].push_back(a);
    }
  }
  cout << "YES\n";
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < graph[i].size(); j++) {
      cout << i << " " << graph[i][j] << '\n';
    }
  }
}
void testcase() {
  long long t;
  cin >> t;
  while (t--) solve();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  testcase();
}
