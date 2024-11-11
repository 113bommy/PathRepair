#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long sz, ans;
string s;
bool u[200005];
vector<int> g[200005];
void dfs(long long v) {
  u[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (!u[g[v][i]]) dfs(g[v][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(7);
  ;
  cin >> sz;
  for (long long i = 0; i < sz; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      g[i].push_back(sz + s[j] - 'a');
      g[sz + (long long)s[j] - 'a'].push_back(i);
    }
  }
  for (long long i = sz; i < sz + 26; i++) {
    if (g[i].size() && !u[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans;
  return 0;
}
