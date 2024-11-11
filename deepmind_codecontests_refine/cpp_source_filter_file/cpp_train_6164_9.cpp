#include <bits/stdc++.h>
using namespace std;
long long let(char c) { return (long long)(c - 'a'); }
vector<long long> g[30];
bool vis[30];
bool is[30];
void dfs(int i) {
  vis[i] = true;
  for (int j = 0; j < g[i].size(); ++j)
    if (!vis[g[i][j]]) {
      dfs(g[i][j]);
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < str.size(); ++j) is[let(str[j])] = true;
    for (int j = 0; j + 1 < str.size(); ++j) {
      long long pomA = let(str[j]);
      long long pomB = let(str[j + 1]);
      g[pomA].push_back(pomB);
      g[pomB].push_back(pomA);
    }
  }
  for (int i = 0; i < 30; ++i) vis[i] = false;
  long long result = 0;
  for (int i = let('a'); i < let('z'); ++i)
    if (!vis[i] && is[i]) {
      dfs(i);
      result++;
    }
  cout << result;
}
