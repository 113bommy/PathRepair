#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> sz;
vector<long long> w;
vector<vector<char> > a;
vector<vector<int> > lessy;
vector<vector<int> > more;
vector<int> color;
vector<bool> used;
bool globok = true;
int find_set(int v) {
  if (par[v] == v)
    return v;
  else
    return par[v] = find_set(par[v]);
}
void make_set(int v) {
  par[v] = v;
  sz[v] = 1;
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
  }
}
void dfs(int v) {
  color[v] = 1;
  for (int i = 0; i < lessy[v].size(); i++) {
    int to = lessy[v][i];
    if (color[to] == 0) {
      dfs(to);
    } else {
      if (color[to] == 1) globok = false;
    }
  }
  color[v] = 2;
}
void usedclear() {
  for (int i = 0; i < used.size(); i++) used[i] = false;
}
void dfs2(int v) {
  for (int i = 0; i < more[v].size(); i++) {
    int to = more[v][i];
    if (w[to] < w[v] + 1) {
      w[to] = w[v] + 1;
      dfs(to);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  w.resize(n + m);
  par.resize(n + m);
  a.resize(n);
  lessy.resize(n + m);
  color.resize(n + m);
  more.resize(n + m);
  used.resize(n + m);
  sz.resize(n + m);
  for (int i = 0; i < par.size(); i++) make_set(i);
  for (int i = 0; i < w.size(); i++) w[i] = -LONG_LONG_MAX;
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '=') {
        union_sets(i, n + j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '=') {
        int x = find_set(n + j);
        int y = find_set(i);
        if (a[i][j] == '<') {
          lessy[x].push_back(y);
          more[y].push_back(x);
        } else {
          lessy[y].push_back(x);
          more[x].push_back(y);
        }
      }
    }
  }
  for (int i = 0; i < lessy.size(); i++) {
    if (color[i] == 0) dfs(i);
  }
  if (!globok) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  vector<int> starts;
  for (int i = 0; i < n + m; i++) {
    if (more[i].size() > 0 && lessy[i].size() == 0) {
      w[i] = 0;
      dfs2(i);
    }
  }
  long long mini = LONG_LONG_MAX;
  for (int i = 0; i < w.size(); i++) {
    int ico = find_set(i);
    mini = min(mini, w[ico]);
  }
  long long add = -mini;
  bool enter = false;
  for (int i = 0; i < w.size(); i++) {
    int ico = find_set(i);
    if (!enter && i >= n) {
      cout << endl;
      enter = true;
    }
    cout << w[ico] + add + 1 << ' ';
  }
}
