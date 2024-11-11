#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
class phase_simplex {
 public:
  int m, n;
  vector<int> B, N;
  vector<vector<double>> D;
  phase_simplex(const vector<vector<double>> &A, const vector<double> &b,
                const vector<double> &c)
      : m(b.size()),
        n(c.size()),
        N(n + 1),
        B(m),
        D(m + 2, vector<double>(n + 2)) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) D[i][j] = A[i][j];
    for (int i = 0; i < m; i++) {
      B[i] = n + i;
      D[i][n] = -1;
      D[i][n + 1] = b[i];
    }
    for (int j = 0; j < n; j++) {
      N[j] = j;
      D[m][j] = -c[j];
    }
    N[n] = -1;
    D[m + 1][n] = 1;
  }
  void Pivot(int r, int s) {
    for (int i = 0; i < m + 2; i++)
      if (i != r)
        for (int j = 0; j < n + 2; j++)
          if (j != s) D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < n + 2; j++)
      if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < m + 2; i++)
      if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }
  bool Simplex(int phase) {
    int x = phase == 1 ? m + 1 : m;
    while (true) {
      int s = -1;
      for (int j = 0; j <= n; j++) {
        if (phase == 2 && N[j] == -1) continue;
        if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s])
          s = j;
      }
      if (D[x][s] > -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
        if (D[i][s] < EPS) continue;
        if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
            (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r])
          r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }
  double Solve(vector<double> &x) {
    int r = 0;
    for (int i = 1; i < m; i++)
      if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m + 1][n + 1] < -EPS)
        return -numeric_limits<double>::infinity();
      for (int i = 0; i < m; i++)
        if (B[i] == -1) {
          int s = -1;
          for (int j = 0; j <= n; j++)
            if (s == -1 || D[i][j] < D[i][s] ||
                D[i][j] == D[i][s] && N[j] < N[s])
              s = j;
          Pivot(i, s);
        }
    }
    if (!Simplex(2)) return numeric_limits<double>::infinity();
    return D[m][n + 1];
  }
};
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<vector<double>> A(2, vector<double>(n));
  int ai, bi;
  for (int i = 0; i < n; i++) {
    cin >> ai >> bi;
    A[0][i] = -ai;
    A[1][i] = -bi;
  }
  vector<double> B(2);
  B[0] = -p;
  B[1] = -q;
  vector<double> C(n, -1.0);
  vector<double> x;
  phase_simplex solver(A, B, C);
  double ans = -solver.Solve(x);
  printf("%.10lf\n", ans);
  return 0;
}
