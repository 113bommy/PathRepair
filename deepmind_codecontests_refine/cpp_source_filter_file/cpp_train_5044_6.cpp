#include <bits/stdc++.h>
using namespace std;
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int N = 3e5 + 10;
int t[N], d[N], d1[N], d2[N];
bool used1[N], used2[N];
int leader(int x) { return (x == t[x]) ? x : t[x] = leader(t[x]); }
bool join(int a, int b) {
  a = leader(a);
  b = leader(b);
  if (a == b) {
    return false;
  }
  int da = (d[a] % 2 == 0) ? d[a] / 2 : d[a] / 2 + 1;
  int db = (d[b] % 2 == 0) ? d[b] / 2 : d[b] / 2 + 1;
  if (rand() % 2 == 0) {
    d[a] = max(d[a], d[b]);
    d[a] = max(d[a], da + db + 1);
    t[b] = a;
  } else {
    d[b] = max(d[a], d[b]);
    d[b] = max(d[a], da + db + 1);
    t[a] = b;
  }
  return true;
}
vector<int> g[N];
int vertex, maxi;
void dfs(int v, int deep) {
  if (deep > maxi) {
    maxi = deep;
    vertex = v;
  }
  used1[v] = true;
  for (int i = 0; i < int(g[v].size()); i++) {
    int u = g[v][i];
    if (!used1[u]) {
      dfs(u, deep + 1);
    }
  }
}
void dfs1(int v, int deep) {
  if (deep > maxi) {
    maxi = deep;
    vertex = v;
  }
  used2[v] = true;
  for (int i = 0; i < int(g[v].size()); i++) {
    int u = g[v][i];
    if (!used2[u]) {
      dfs1(u, deep + 1);
    }
  }
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < int(N); i++) {
    t[i] = i;
  }
  for (int i = 0; i < int(m); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    join(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < int(n); i++) {
    if (!used1[i]) {
      vertex = -1;
      maxi = -1;
      dfs(i, 0);
      dfs1(vertex, 0);
      d[leader(i)] = maxi;
    }
  }
  for (int i = 0; i < int(q); i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x;
      scanf("%d", &x);
      x--;
      printf("%d\n", d[leader(x)]);
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      x--;
      y--;
      join(x, y);
    }
  }
  return 0;
}
