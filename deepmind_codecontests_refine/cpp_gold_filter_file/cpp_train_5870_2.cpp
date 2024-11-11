#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e2 + 100;
int a[MAXN], b[MAXN];
int nt(int i) { return 2 * i + 1; }
int tn(int i) { return 2 * i; }
bool check(int a, int b, int cc, int dd) {
  int d = max(cc, dd), c = min(cc, dd);
  if ((c < a && a < d) && (b > d | b < c)) {
    return 1;
  }
  if ((c < b && b < d) && (a > d | a < c)) {
    return 1;
  }
  return 0;
}
bool vis[MAXN], ans[MAXN];
vector<int> Sat[MAXN], C;
vector<pair<int, int> > Clause;
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < Sat[u].size(); i++) {
    int q = Sat[u][i];
    if (!vis[q]) {
      dfs(q);
    }
  }
  C.push_back(u);
}
void addclause(int u, int v) {
  int u2 = u + 1, v2 = v + 1;
  if (u % 2) {
    u2 -= 2;
  }
  if (v % 2) {
    v2 -= 2;
  }
  Sat[u2].push_back(v);
  Sat[v2].push_back(u);
  Clause.push_back({u, v});
}
bool solve(int m) {
  for (int i = 0; i < m; i++) {
    vis[i] = 0;
    ans[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < m; i++) {
    vis[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    if (!vis[C[i] / 2]) {
      if (C[i] % 2) {
        ans[C[i] / 2] = 1;
      } else {
        ans[C[i] / 2] = 0;
      }
      vis[C[i] / 2] = 1;
    }
  }
  bool P = 1;
  for (int i = 0; i < Clause.size(); i++) {
    int u = Clause[i].first, v = Clause[i].second;
    bool x = ans[u / 2], y = ans[v / 2];
    if (u % 2) {
      x = !x;
    }
    if (v % 2) {
      y = !y;
    }
    P = P & (x | y);
  }
  return P;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (check(a[i], b[i], a[j], b[j])) {
        addclause(tn(i), tn(j));
        addclause(nt(i), nt(j));
      }
    }
  }
  if (solve(2 * m)) {
    for (int i = 0; i < m; i++) {
      if (ans[i]) {
        cout << 'i';
      } else {
        cout << 'o';
      }
    }
    cout << endl;
    return 0;
  }
  cout << "Impossible" << endl;
  return 0;
}
