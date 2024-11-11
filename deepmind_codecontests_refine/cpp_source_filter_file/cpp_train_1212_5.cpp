#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long PotInt(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long p = PotInt(a, n / 2);
    return (p * p) % MOD;
  }
  return (a * PotInt(a, n - 1)) % MOD;
}
vector<vector<long long> > Mnoz(vector<vector<long long> > a,
                                vector<vector<long long> > b) {
  vector<vector<long long> > c(9, vector<long long>(9, 0));
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
      for (int k = 0; k < 9; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
  return c;
}
vector<vector<long long> > PotMat(vector<vector<long long> > a, long long n) {
  vector<vector<long long> > id(9, vector<long long>(9, 0));
  for (int i = 0; i < 9; ++i) id[i][i] = 1;
  if (n == 0) return id;
  if (n % 2 == 0) {
    vector<vector<long long> > p = PotMat(a, n / 2);
    return Mnoz(p, p);
  }
  return Mnoz(a, PotMat(a, n - 1));
}
long long Ile(long long n) {
  if (n == 0) return 0;
  if (n == 1) return 8;
  vector<vector<long long> > mat(9, vector<long long>(9, 0));
  mat[0][2] = 1;
  mat[1][4] = 1;
  mat[2][0] = mat[2][6] = 1;
  mat[3][0] = mat[3][6] = 1;
  mat[4][1] = mat[4][7] = 1;
  mat[5][1] = mat[5][7] = 1;
  mat[6][3] = mat[6][5] = 1;
  mat[7][3] = mat[7][5] = 1;
  mat[8][2] = mat[8][4] = mat[8][8] = 1;
  mat[8][0] = mat[8][1] = mat[8][3] = mat[8][5] = mat[8][6] = mat[8][7] = 2;
  mat = PotMat(mat, n - 2);
  long long odp = 8;
  for (int i = 0; i < 8; ++i) odp = (odp + mat[8][i]) % MOD;
  odp = (odp + 8 * mat[8][8]) % MOD;
  return odp;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long L, R;
  cin >> L >> R;
  long long odp = 0;
  odp += Ile(R);
  odp -= Ile(L - 1);
  if (odp < 0) odp += MOD;
  if (R - L + 1 >= 2 || L % 2 == 1) {
    if (L % 2 == 0) ++L;
    if (R % 2 == 0) --R;
    odp = (odp + Ile((R + 1) / 2)) % MOD;
    odp -= Ile((L + 1) / 2 - 1);
    if (odp < 0) odp += MOD;
  }
  odp = (odp * PotInt(2, MOD - 2)) % MOD;
  cout << odp;
  return 0;
}
