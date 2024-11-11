#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, fa[N], inDeg[N], val[N];
string s[1005];
vector<int> g[N];
int fi(int x) { return fa[x] == x ? x : fi(fa[x]); }
void unite(int x, int y) { fa[fi(y)] = fi(x); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) fa[i] = i;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '=') unite(i, j + n);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '<') {
        g[fi(i)].emplace_back(fi(j + n));
        inDeg[fi(j + n)]++;
      }
      if (s[i][j] == '>') {
        g[fi(j + n)].emplace_back(fi(i));
        inDeg[fi(i)]++;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n + m; i++) {
    if (fi(i) == i && !inDeg[i]) {
      q.push(i);
      val[i] = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      inDeg[g[u][i]]--;
      val[g[u][i]] = val[u] + 1;
      if (!inDeg[g[u][i]]) q.push(g[u][i]);
    }
  }
  for (int i = 0; i < n + m; i++) {
    if (inDeg[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << val[fi(i)] << " ";
  cout << endl;
  for (int i = n; i < n + m; i++) cout << val[fi(i)] << " ";
  cout << endl;
  return 0;
}
