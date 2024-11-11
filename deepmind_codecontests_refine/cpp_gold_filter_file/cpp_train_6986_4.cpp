#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end() {}
namespace Simplex {
const int N = 505, M = 2550;
const double INF = 3e9;
const double eps = 1e-6;
int n, m;
double a[M][N], b[M], c[N], v, A[M][N];
int idx[N], idy[M];
void pivot(const int &e, const int &l) {
  double tmp = -A[l][e];
  for (int i = 0; i <= n; i++)
    if (i != e) A[l][i] /= tmp;
  A[l][e] = -1 / tmp;
  for (int i = 0; i <= m; i++) {
    if (i == l) continue;
    for (int j = 0; j <= n; j++) {
      if (j == e) continue;
      A[i][j] += A[i][e] * A[l][j];
    }
    A[i][e] *= A[l][e];
  }
  swap(idx[e], idy[l]);
}
double ans[N];
double simplex() {
  srand(time(0));
  for (int i = 1; i <= n; ++i) A[0][i] = c[i];
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) A[i][j] = -a[i][j];
    A[i][0] = b[i];
  }
  for (int i = 1; i <= n; i++) idx[i] = i;
  for (int i = 1; i <= m; i++) idy[i] = n + i;
  int x, y;
  while (1) {
    x = y = 0;
    for (int i = 1; i <= m; i++)
      if (A[i][0] < -eps) {
        y = i;
        if (rand() % 3 == 0) break;
      }
    if (!y) break;
    for (int i = 1; i <= n; i++)
      if (A[y][i] > eps) {
        x = i;
        if (rand() % 3 == 0) break;
      }
    if (!x) return -INF;
    pivot(x, y);
  }
  while (1) {
    x = y = 0;
    for (int i = 1; i <= n; i++)
      if (A[0][i] > eps) {
        x = i;
        break;
      }
    if (!x) break;
    double temp = INF;
    for (int i = 1; i <= m; i++)
      if (A[i][x] < -eps) {
        double nt = A[i][0] / -A[i][x];
        if (nt < temp) temp = nt, y = i;
      }
    if (!y) return INF;
    pivot(x, y);
  }
  return A[0][0];
}
}  // namespace Simplex
int n, rx, ry;
vector<int> e1[N], e2[N];
int a[N];
int depx[N], depy[N];
void dfsdepx(int u, int fa) {
  depx[u] = depx[fa] + 1;
  for (auto v : e1[u]) {
    if (v == fa) continue;
    dfsdepx(v, u);
  }
}
void dfsdepy(int u, int fa) {
  depy[u] = depy[fa] + 1;
  for (auto v : e2[u]) {
    if (v == fa) continue;
    dfsdepy(v, u);
  }
}
void dfsx(int u, int fa, int k, int f) {
  Simplex::a[k][u] = f;
  for (auto v : e1[u]) {
    if (v == fa || depx[v] < depx[u]) continue;
    dfsx(v, u, k, f);
  }
}
void dfsy(int u, int fa, int k, int f) {
  Simplex::a[k][u] = f;
  for (auto v : e2[u]) {
    if (v == fa || depy[v] < depy[u]) continue;
    dfsy(v, u, k, f);
  }
}
inline void solve() {
  scanf("%d%d%d", &n, &rx, &ry);
  Simplex::n = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    Simplex::c[i] = a[i];
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e1[x].push_back(y);
    e1[y].push_back(x);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e2[x].push_back(y);
    e2[y].push_back(x);
  }
  dfsdepx(rx, 0);
  dfsdepy(ry, 0);
  int K = 0;
  for (int i = 1; i <= n; ++i) {
    K++;
    Simplex::b[K] = 1;
    Simplex::a[K][i] = 1;
  }
  int qx, qy;
  scanf("%d", &qx);
  while (qx--) {
    int k, x;
    scanf("%d%d", &k, &x);
    K++;
    Simplex::b[K] = x;
    dfsx(k, 0, K, 1);
    K++;
    Simplex::b[K] = -x;
    dfsx(k, 0, K, -1);
  }
  scanf("%d", &qy);
  while (qy--) {
    int k, x;
    scanf("%d%d", &k, &x);
    K++;
    Simplex::b[K] = x;
    dfsy(k, 0, K, 1);
    K++;
    Simplex::b[K] = -x;
    dfsy(k, 0, K, -1);
  }
  Simplex::m = K;
  double ans = Simplex::simplex();
  if (ans == -Simplex::INF) return puts("-1"), void();
  int ans2 = ans + 0.5;
  cout << ans2 << endl;
}
int main() {
  TIME__START = clock();
  int Test = 1;
  while (Test--) {
    solve();
  }
  TIME__END = clock();
  program_end();
  return 0;
}
