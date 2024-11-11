#include <bits/stdc++.h>
using namespace std;
long long n;
vector<vector<long long>> adj;
vector<vector<long long>> adjtranspose;
vector<bool> visited1;
vector<bool> visited2;
stack<long long> st;
vector<long long> color;
vector<vector<long long>> SCC;
long long k;
void dfs1(long long node) {
  visited1[node] = true;
  for (auto x : adj[node]) {
    if (!visited1[x]) {
      dfs1(x);
    }
  }
  st.push(node);
}
void dfs2(long long node, long long c) {
  visited2[node] = true;
  color[node] = c;
  for (auto x : adjtranspose[node]) {
    if (!visited2[x]) {
      dfs2(x, c);
    }
  }
}
void condense_directed_graph() {
  for (long long i = 1; i <= n; i++) {
    if (!visited1[i]) {
      dfs1(i);
    }
  }
  long long c = 1;
  while (!st.empty()) {
    long long x = st.top();
    st.pop();
    if (!visited2[x]) {
      dfs2(x, c++);
    }
  }
  SCC.resize(c);
  if (c - 1 < k) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 1; i <= n; i++) {
    cout << (char)(min(color[i] - 1, k - 1) + 'a');
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> k;
  adj.resize(n + 1);
  adjtranspose.resize(n + 1);
  visited1.resize(n + 1, false);
  visited2.resize(n + 1, false);
  color.resize(n + 1);
  long long a[n];
  long long b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    adj[a[i]].push_back(a[i + 1]);
    adj[b[i]].push_back(b[i + 1]);
    adjtranspose[b[i + 1]].push_back(b[i]);
    adjtranspose[a[i + 1]].push_back(a[i]);
  }
  condense_directed_graph();
}
