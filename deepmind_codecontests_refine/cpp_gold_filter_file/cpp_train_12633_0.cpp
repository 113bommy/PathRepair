#include <bits/stdc++.h>
using namespace std;
const int N = 107;
struct pt {
  long double x, y;
  pt(long double x = 0.0, long double y = 0.0) : x(x), y(y) {}
} mas[5 * N];
int n, m;
const long double pi = acosl(-1.0);
vector<vector<int> > a;
bool G[5 * N][5 * N];
vector<int> order;
void dfs(int u) {
  for (int to = 0; to < m; ++to) {
    if (G[u][to]) {
      G[u][to] = false;
      G[to][u] = false;
      dfs(to);
    }
  }
  order.push_back(u);
}
int main() {
  long double fi = 2.0 * pi / 5.0;
  long double len = 5.0 / sinl(fi / 2.0);
  long double delta = (pi - 2 * fi) / 2.0;
  for (int i = 0; i < 5; ++i) {
    mas[m].x = len * cosl(delta + i * fi);
    mas[m].y = len * sinl(delta + i * fi);
    ++m;
  }
  long double diff = 2.0 * len * sinl(fi);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < 5; ++i) a[0].push_back(i);
  for (int i = 1; i < n; ++i) {
    int prv;
    if (i == 1)
      prv = 5;
    else
      prv = 4;
    mas[m].x = mas[m - prv].x + diff;
    mas[m].y = mas[m - prv].y;
    a[i].push_back(m);
    ++m;
    mas[m].x = mas[m - prv].x + diff;
    mas[m].y = mas[m - prv].y;
    a[i].push_back(m);
    ++m;
    if (prv == 5)
      a[i].push_back(0);
    else
      a[i].push_back(5 + (i - 2) * 4);
    if (prv == 5) prv = 4;
    mas[m].x = mas[m - prv].x + diff;
    mas[m].y = mas[m - prv].y;
    a[i].push_back(m);
    ++m;
    mas[m].x = mas[m - prv].x + diff;
    mas[m].y = mas[m - prv].y;
    a[i].push_back(m);
    ++m;
  }
  for (int i = 0; i < n; ++i) {
    int a1 = a[i][0];
    int a2 = a[i][1];
    int a3 = a[i][2];
    int a4 = a[i][3];
    int a5 = a[i][4];
    G[a1][a3] = true;
    G[a1][a4] = true;
    G[a2][a4] = true;
    G[a2][a5] = true;
    G[a3][a5] = true;
    G[a3][a1] = true;
    G[a4][a1] = true;
    G[a4][a2] = true;
    G[a5][a2] = true;
    G[a5][a3] = true;
  }
  dfs(0);
  cout << m << endl;
  for (int i = 0; i < m; ++i)
    cout << fixed << setprecision(12) << mas[i].x << " " << mas[i].y << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) cout << a[i][j] + 1 << " ";
    cout << endl;
  }
  for (int i : order) cout << i + 1 << " ";
  cout << endl;
  return 0;
}
