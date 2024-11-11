#include <bits/stdc++.h>
using namespace std;
int vis[100001], level[100001], a[100001], b[100001];
vector<int> v[100001];
void dfs() {
  stack<int> s;
  s.push(1);
  vis[1] = 1;
  level[1] = 0;
  while (!s.empty()) {
    int p = s.top();
    s.pop();
    for (int i = 0; i < v[p].size(); i++) {
      if (vis[v[p][i]] == 0) {
        level[v[p][i]] = level[p] + 1;
        a[p] += a[v[p][i]];
        a[v[p][i]] = 0;
        vis[v[p][i]] = 1;
        s.push(v[p][i]);
      }
    }
    a[p] = a[p] % 2;
    b[level[p]] += a[p];
  }
}
int main() {
  int n, val;
  cin >> n;
  memset(a, 1, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(vis, 0, sizeof(vis));
  memset(level, -1, sizeof(level));
  a[1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> val;
    v[val].push_back(i);
    v[i].push_back(val);
  }
  dfs();
  int sum = 0;
  for (int i = 0; i <= 100000; i++) {
    b[i] = b[i] % 2;
    sum += b[i];
  }
  cout << sum + 1;
  return 0;
}
