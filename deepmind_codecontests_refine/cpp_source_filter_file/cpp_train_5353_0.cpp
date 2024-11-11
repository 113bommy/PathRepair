#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using vd = vector<ld>;
using vvd = vector<vd>;
using vi = vector<int>;
using vvii = vector<vector<pair<int, int>>>;
const ld EPS = 1e-9;
struct LPSolver {
  int m, n;
  vi B, N;
  vvd D;
  LPSolver(const vvd &A, const vd &b, const vd &c)
      : m(((int)b.size())),
        n(((int)c.size())),
        N(n + 1),
        B(m + 1),
        D(m + 1, vd(n + 1, 0)) {
    for (int i = 0; i < (m); i++) {
      for (int j = 0; j < (n); j++) D[i + 1][j] = A[i][j];
      D[i + 1][n] = b[i];
    }
    for (int i = 0; i < (n); i++) D[0][i] = -c[i];
    for (int i = 0; i < (m + 1); i++) B[i] = -i;
    for (int j = 0; j < (n + 1); j++) N[j] = j;
  }
  void Pivot(int r, int s) {
    for (int i = 0; i < (m + 1); i++)
      if (i != r && ((D[i][s] > EPS) || (D[i][s] < -EPS)))
        for (int j = 0; j < (n + 1); j++)
          if (j != s) D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < (n + 1); j++)
      if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < (m + 1); i++)
      if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }
  ld Solve(vector<ld> &x) {
    while (true) {
      int ii = 1, jj = 0;
      for (int i = 1; i <= (m); i++)
        if (make_pair(D[i][n], B[i]) < make_pair(D[ii][n], B[ii])) ii = i;
      if (D[ii][n] > -EPS) break;
      for (int j = 0; j < (n); j++)
        if (D[ii][j] < D[ii][jj]) jj = j;
      if (D[ii][jj] > -EPS) return -numeric_limits<ld>::infinity();
      Pivot(ii, jj);
    }
    while (true) {
      int ii = 1, jj = 0;
      for (int j = 0; j < (n); j++)
        if (make_pair(D[0][j], N[j]) < make_pair(D[0][jj], N[jj])) jj = j;
      if (D[0][jj] > -EPS) break;
      for (int i = 1; i <= (m); i++)
        if (D[i][jj] > -EPS &&
            (D[ii][jj] < EPS || make_pair(D[i][n] / D[i][jj], B[i]) <
                                    make_pair(D[ii][n] / D[ii][jj], B[ii])))
          ii = i;
      if (D[ii][jj] < EPS) return numeric_limits<ld>::infinity();
      Pivot(ii, jj);
    }
    x.assign(n, 0);
    for (int i = 1; i <= (m); i++)
      if (B[i] > EPS) x[B[i]] = D[i][n];
    return D[0][n];
  }
};
vvii adj;
void dfs(vector<int> &d, int v, int p, int dist, int x) {
  d[v] = dist;
  for (auto pr : adj[v])
    if (pr.first != p && dist + pr.second <= x)
      dfs(d, pr.first, v, dist + pr.second, x);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x, color, u, v, w;
  cin >> n >> x;
  vvd A(n + 2, vd(n));
  vd B(n + 2, -1), C(n);
  B[n] = 0;
  for (int i = 0; i < (n); i++) {
    cin >> color;
    if (color == 0)
      C[i] = -1;
    else {
      C[i] = 0;
      B[n]++;
    }
  }
  adj.resize(n);
  vector<vector<int>> tr(n, vector<int>(n, x + 1));
  for (int i = 0; i < (n - 1); i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (int i = 0; i < (n); i++) dfs(tr[i], i, -1, 0, x);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++) A[i][j] = tr[i][j] > x ? 0 : -1;
  B[n + 1] = -B[n];
  fill(A[n].begin(), A[n].end(), 1);
  fill(A[n + 1].begin(), A[n + 1].end(), -1);
  LPSolver LPS(A, B, C);
  vd X;
  int ans = round(-LPS.Solve(X));
  cout << (((int)X.size()) < n ? -1 : ans) << endl;
  return 0;
}
