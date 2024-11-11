#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> u;
vector<vector<int> > p;
vector<int> subtree;
vector<int> tin, tout;
int T = 0;
void dfs(int v) {
  u[v] = 1;
  tin[v] = ++T;
  subtree[v] = 1;
  for (int i = 0; i < (int)(g[v]).size(); ++i) {
    int to = g[v][i];
    if (!u[to]) {
      p[to][0] = v;
      dfs(to);
      subtree[v] += subtree[to];
    }
  }
  tout[v] = ++T;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  u.resize(n);
  p.resize(n, vector<int>(20));
  tin.resize(n);
  tout.resize(n);
  subtree.resize(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < 20; ++j) {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a == b) {
      cout << n << endl;
      continue;
    }
    int lena = 0, lenb = 0;
    int a1 = a, b1 = b;
    for (int j = 19; j >= 0; --j) {
      int x = p[a1][j];
      if (tin[x] <= tin[b] && tout[x] >= tout[b]) {
        continue;
      } else {
        a1 = x;
        lena += (1 << j);
      }
    }
    for (int j = 19; j >= 0; --j) {
      int x = p[b1][j];
      if (tin[x] <= tin[a] && tout[x] >= tout[a]) {
        continue;
      } else {
        b1 = x;
        lenb += (1 << j);
      }
    }
    int lca;
    if (tin[b] < tin[a] && tout[b] > tout[a]) {
      lca = b;
      lena++;
    } else if (tin[a] < tin[b] && tout[a] > tout[b]) {
      lca = a;
      lenb++;
    } else {
      lca = p[a1][0];
      ++lena;
      ++lenb;
    }
    if ((lena + lenb) % 2 != 0) {
      cout << 0 << endl;
      continue;
    }
    int len = (lena + lenb) / 2;
    if (lena == lenb) {
      cout << n - subtree[a1] - subtree[b1] << endl;
      continue;
    }
    if (lena < lenb) {
      swap(lena, lenb);
      swap(a, b);
      swap(a1, b1);
    }
    a1 = a;
    --len;
    for (int j = 19; j >= 0; --j) {
      if ((1 << j) > len) {
        continue;
      } else {
        a1 = p[a1][j];
        len -= (1 << j);
      }
    }
    int x = p[a1][0];
    cout << subtree[x] - subtree[a1] << endl;
  }
}
