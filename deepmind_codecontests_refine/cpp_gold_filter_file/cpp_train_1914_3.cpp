#include <bits/stdc++.h>
using namespace std;
vector<int> g[100];
int v[100];
int dfs(int i, int n) {
  v[i] = 1;
  if (i == n) {
    return 1;
  }
  for (auto j : g[i]) {
    if (v[j] == 0) {
      if (dfs(j, n) == 1) {
        return 1;
      }
    }
  }
  v[i] = 2;
  return 0;
}
int main() {
  int n, i, x, y, e, ansx = -1, ansy = -1;
  int d[100] = {0};
  cin >> n;
  e = n * (n - 1) / 2;
  for (i = 0; i < e - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    d[x]++;
    d[y]++;
  }
  for (i = 1; i <= n; i++) {
    if (d[i] == n - 2) {
      if (ansx == -1) {
        ansx = i;
      } else {
        ansy = i;
      }
    }
  }
  if (dfs(ansx, ansy) == 1) {
    cout << ansx << " " << ansy << endl;
  } else {
    cout << ansy << " " << ansx << endl;
  }
  return 0;
}
