#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[112345];
vector<int> g[112345];
int k[112345], mass[112345];
bool b[112345];
vector<int> v, leaf;
set<int> st;
bool check(int i) {
  int j;
  for (j = 0; j < min(a[i].size(), a[i + 1].size()); j++)
    if (a[i][j] != a[i + 1][j]) {
      if (a[i][j] > a[i + 1][j]) {
        if (k[a[i][j]] == 3)
          return false;
        else
          k[a[i][j]] = 2;
        if (k[a[i + 1][j] == 2])
          return false;
        else
          k[a[i + 1][j]] = 3;
      } else
        g[a[i + 1][j]].push_back(a[i][j]);
      return true;
    }
  if (a[i].size() <= a[i + 1].size()) return true;
  return false;
}
void dfs(int v) {
  b[v] = true;
  st.insert(k[v]);
  leaf.push_back(v);
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (!b[to]) dfs(to);
  }
  return;
}
int main() {
  int i, j, curr, x;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> curr;
    for (j = 0; j < curr; j++) {
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (i = 0; i <= m; i++) {
    k[i] = 1;
    b[i] = false;
    mass[i] = 3;
  }
  for (i = 0; i < n - 1; i++)
    if (!check(i)) {
      cout << "No";
      return 0;
    }
  for (i = m; i > 0; i--)
    if (b[i] == false && k[i] != 1) {
      leaf.clear();
      st.clear();
      dfs(i);
      if (st.count(2) > 0 && st.count(3) > 0) {
        cout << "No";
        return 0;
      }
      curr = *st.rbegin();
      for (j = 0; j < leaf.size(); j++) mass[leaf[j]] = curr;
    }
  for (i = 1; i <= m; i++)
    if (mass[i] == 2) v.push_back(i);
  cout << "Yes" << endl;
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
