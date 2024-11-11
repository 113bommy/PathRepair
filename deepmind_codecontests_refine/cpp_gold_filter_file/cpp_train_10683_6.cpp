#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
vector<int> a[maxn];
vector<int> e[maxn];
bool b[maxn];
void dfs(int x) {
  for (int i = 0; i < e[x].size(); i++) {
    int v = e[x][i];
    if (b[v]) continue;
    b[v] = 1;
    dfs(v);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  bool fail = false;
  for (int i = 1; i < n; i++) {
    bool same = true;
    for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
      if (a[i][j] == a[i + 1][j]) continue;
      if (a[i][j] < a[i + 1][j]) {
        e[a[i + 1][j]].push_back(a[i][j]);
      } else {
        b[a[i][j]] = 1;
      }
      same = false;
      break;
    }
    if (same && a[i].size() > a[i + 1].size()) {
      fail = true;
      break;
    }
  }
  if (fail) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (b[i]) dfs(i);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
      if (a[i][j] == a[i + 1][j]) continue;
      if (a[i][j] < a[i + 1][j]) {
      } else {
        if (b[a[i + 1][j]]) fail = true;
      }
      break;
    }
    if (fail) break;
  }
  if (fail) {
    cout << "No" << endl;
    return 0;
  }
  int ret = 0;
  cout << "Yes" << endl;
  for (int i = 1; i <= m; i++) {
    if (b[i]) ret++;
  }
  cout << ret << endl;
  for (int i = 1; i <= m; i++) {
    if (b[i]) {
      cout << i;
      ret--;
      if (ret)
        cout << " ";
      else
        cout << endl;
    }
  }
  return 0;
}
