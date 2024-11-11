#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const int mod = 1e9 + 7;
vector<int> d;
map<int, int> brid;
int sum(long long a, long long b) { return (a + b) % mod; }
int mul(long long a, long long b) { return (a * b) % mod; }
struct matrica {
  vector<vector<int> > mat;
  matrica() { mat = vector<vector<int> >(N, vector<int>(N, 0)); }
  void neutral() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == j)
          mat[i][j] = 1;
        else
          mat[i][j] = 0;
      }
    }
  }
  void prij() {
    for (int i = 0; i < N - 2; ++i) {
      mat[i][i + 1] = 1;
    }
    for (int i = 0; i < (int)d.size(); ++i) {
      mat[N - 2][N - d[i] - 1] = brid[d[i]];
    }
    mat[N - 1][N - 2] = mat[N - 1][N - 1] = 1;
  }
  void ispis() {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << mat[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
  matrica friend operator*(matrica a, matrica b) {
    matrica c;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          long long x = c.mat[i][j] + mul(a.mat[i][k], b.mat[k][j]);
          c.mat[i][j] = x % mod;
        }
      }
    }
    return c;
  }
};
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (!brid[a]) d.push_back(a);
    brid[a]++;
  }
  matrica sol;
  sol.neutral();
  matrica exp;
  exp.prij();
  for (int i = 0; (1 << i) <= x; ++i) {
    if ((1 << i) & x) sol = sol * exp;
    exp = exp * exp;
  }
  matrica desna;
  desna.mat[N - 2][0] = 1;
  sol = sol * desna;
  cout << sum(sol.mat[N - 1][0], sol.mat[N - 2][0]) << "\n";
  return 0;
}
