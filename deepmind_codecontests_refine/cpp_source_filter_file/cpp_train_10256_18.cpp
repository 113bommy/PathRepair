#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
struct LPSolver {
  int m, n;
  vector<int> B, N;
  vector<vector<long double> > D;
  LPSolver(const vector<vector<long double> > &A, const vector<long double> &b,
           const vector<long double> &c)
      : m(b.size()),
        n(c.size()),
        N(n + 1),
        B(m),
        D(m + 2, vector<long double>(n + 2)) {
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
  long double Solve(vector<long double> &x) {
    int r = 0;
    for (int i = 1; i < m; i++)
      if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m + 1][n + 1] < -EPS)
        return -numeric_limits<long double>::infinity();
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
    if (!Simplex(2)) return numeric_limits<long double>::infinity();
    x = vector<long double>(n);
    for (int i = 0; i < m; i++)
      if (B[i] < n) x[B[i]] = D[i][n + 1];
    return D[m][n + 1];
  }
};
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<vector<long double> > A(2, vector<long double>(n));
  int ra, rb;
  for (int i = 0; i < n; i++) {
    cin >> ra >> rb;
    A[0][i] = -ra;
    A[1][i] = -rb;
  }
  vector<long double> B(2);
  B[0] = -p;
  B[1] = -q;
  vector<long double> C(n, -1.0);
  vector<long double> x;
  LPSolver solver(A, B, C);
  long double ans = -solver.Solve(x);
  cout << setiosflags(ios::fixed);
  cout << setprecision(10) << ans - 2 << endl;
  return 0;
}
