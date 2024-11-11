#include <bits/stdc++.h>
using namespace std;
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
long long mod;
struct matrix {
  vector<vector<long long>> mat;
  matrix(long long n, long long m, long long num = -1) {
    mat.resize(n);
    if (num == -1)
      for (int i = 0; i < n; ++i) {
        mat[i].resize(m, 0);
        mat[i][i] = 1;
      }
    else
      for (int i = 0; i < n; ++i) mat[i].resize(m, num);
  }
};
vector<vector<long long>> multi_matrix(vector<vector<long long>> a,
                                       vector<vector<long long>> b) {
  matrix c(a.size(), b[0].size(), 0);
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b[0].size(); ++j) {
      for (int k = 0; k < b.size(); ++k)
        c.mat[i][j] += (a[i][k] % mod * b[k][j] % mod) % mod,
            c.mat[i][j] %= mod;
    }
  return c.mat;
}
vector<vector<long long>> matrix_power(vector<vector<long long>> a,
                                       long long k) {
  if (k == 0) {
    matrix c(a.size(), a.size());
    return c.mat;
  }
  if (k % 2 == 1) return multi_matrix(a, matrix_power(a, k - 1));
  return matrix_power(multi_matrix(a, a), k / 2);
}
int main() {
  long long n, x, y;
  cin >> n >> x >> y >> mod;
  matrix ini(2, 2, 1), tra(2, 2, 1);
  long long f, l1, l2, sum = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    if (!i) f = a;
    if (i == n - 2) l1 = a;
    l2 = a;
    sum += a;
    sum %= mod;
  }
  if (n == 1) return (cout << f << "\n", 0);
  ini.mat[0][0] = sum;
  tra.mat[0][0] = 3, tra.mat[1][0] = -(f + l2), tra.mat[0][1] = 0;
  sum = multi_matrix(ini.mat, matrix_power(tra.mat, x))[0][0];
  sum = (sum + mod) % mod;
  ini.mat[0][0] = l2, ini.mat[0][1] = l1;
  tra.mat[0][0] = tra.mat[0][1] = tra.mat[1][0] = 1, tra.mat[1][1] = 0;
  l2 = multi_matrix(ini.mat, matrix_power(tra.mat, x))[0][0];
  l2 %= mod;
  ini.mat[0][0] = sum, ini.mat[0][1] = ini.mat[1][0] = ini.mat[1][1] = 1;
  tra.mat[0][0] = 3, tra.mat[1][0] = -(f + l2), tra.mat[0][1] = 0,
  tra.mat[1][1] = 1;
  sum = multi_matrix(ini.mat, matrix_power(tra.mat, y))[0][0];
  sum = (sum + mod) % mod;
  cout << sum << "\n";
}
