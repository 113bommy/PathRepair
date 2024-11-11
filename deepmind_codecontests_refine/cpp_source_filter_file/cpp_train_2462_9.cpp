#include <bits/stdc++.h>
using namespace std;
vector<int> v[100000];
int vis[100000] = {0};
int level[100000] = {0};
int h[100000] = {0};
void dfs(int s, int level) {
  h[level]++;
  vis[s] = 1;
  for (int i = 0; i < v[s].size(); i++) {
    if (!vis[v[s][i]]) {
      dfs(v[s][i], level + 1);
    }
  }
}
int main() {
  int n, m;
  cin >> n;
  m = n;
  for (int i = 2; i <= m; i++) {
    int x, y;
    cin >> x;
    y = i;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int q;
  int ar[100000] = {0};
  int d;
  dfs(1, 0);
  int ct = 1;
  for (int i = 1; i < 10000; i++) {
    if (h[i] % 2 != 0) ct++;
  }
  cout << ct;
  return 0;
}
