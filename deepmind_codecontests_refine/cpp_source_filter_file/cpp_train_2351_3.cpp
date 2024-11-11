#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n, m;
vector<vector<long long> > v(200005);
vector<long long> vis(200005);
vector<long long> vis1(200005);
long long flag = 0;
long long ct = 0;
void dfs(long long ind) {
  vis[ind] = 1;
  ct++;
  vector<long long> j = v[ind];
  for (long long i = 0; i < j.size(); i++) {
    if (vis[j[i]] == 0) {
      dfs(j[i]);
    }
  }
}
void dfs1(long long ind, long long c) {
  vis1[ind] = 1;
  if (v[ind].size() != c) flag = 0;
  vector<long long> j = v[ind];
  for (long long i = 0; i < j.size(); i++) {
    if (vis1[j[i]] == 0) {
      dfs(j[i]);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  long long a, b;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      ct = 0;
      dfs(i);
      flag = 1;
      dfs1(i, ct - 1);
      if (flag == 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
