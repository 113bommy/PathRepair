#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
const long double eps = 1e-18;
long double add[maxn], f[maxn];
int a[maxn], sz[maxn];
int n;
vector<int> ed[maxn];
void dfs(int x) {
  sz[x] = 1;
  for (int i = 0; i < ed[x].size(); i++) {
    int to = ed[x][i];
    dfs(to);
    sz[x] += sz[to];
  }
}
void go(int x) {
  for (int i = 0; i < ed[x].size(); i++) {
    int to = ed[x][i];
    add[to] += add[x];
  }
  int v = 0;
  for (int i = 0; i < ed[x].size(); i++) {
    int to = ed[x][i];
    v++;
    a[v] = sz[to];
  }
  if (v == 1) {
    add[ed[x][0]]++;
    go(ed[x][0]);
  } else {
    for (int i = 1; i <= v; i++) {
      int s = sz[x] - 1 - a[i];
      add[ed[x][i - 1]] += 1 + 0.5 * s;
    }
    for (int i = 1; i <= v; i++) go(ed[x][i - 1]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    ed[x].push_back(i);
  }
  add[1] = 1;
  dfs(1);
  go(1);
  cout.precision(9);
  for (int i = 1; i <= n; i++) cout << fixed << add[i] << " ";
  cout << "\n";
  return 0;
}
