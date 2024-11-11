#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<vector<int> > v(100001);
vector<int> vis(100001);
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
int dfs(int src) {
  stack<int> st;
  int cnt = 0;
  st.push(src);
  vis[src] = 1;
  cnt++;
  while (!st.empty()) {
    int x = st.top();
    st.pop();
    if (!vis[x]) {
      cnt++;
      vis[x] = 1;
    }
    for (int i = 0; i < v[x].size(); i++) {
      if (vis[v[x][i]] == 0) st.push(v[x][i]);
    }
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  fill(vis.begin(), vis.end(), 0);
  for (int i = 0; i < v.size(); i++) v[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    if (c == 0) {
      v[x].push_back(y);
      v[y].push_back(x);
    }
  }
  long long ans = binpow(n, k);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = (ans - binpow(dfs(i), k)) % mod;
    }
  }
  cout << ans << endl;
}
