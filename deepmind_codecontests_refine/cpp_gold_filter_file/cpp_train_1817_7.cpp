#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int mxN = 510;
const int mxT = 110;
const double EPS = 1e-12;
double mat[mxN][mxN << 2];
double cnt[mxN][mxN];
vector<int> g[mxN];
bool dcr[mxN];
int N;
void gauss() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dcr[j]) mat[i][j + N] = cnt[i][j] / g[i].size();
    }
  }
  for (int r = 0, col = 0; col < N; col++) {
    for (int s = r; s < N; s++) {
      if (fabs(mat[s][col]) >= EPS) {
        if (r != s)
          for (int c = 0; c < N + N; c++) swap(mat[r][c], mat[s][c]);
        break;
      }
    }
    if (fabs(mat[r][col]) < EPS) continue;
    for (int k = col + 1; k < N + N; k++) mat[r][k] /= mat[r][col];
    mat[r][col] = 1;
    for (int o = 0; o < N; o++) {
      if (o == r) continue;
      if (fabs(mat[o][col]) < EPS) continue;
      for (int c = col; c < N + N; c++)
        if (c != col) mat[o][c] -= mat[r][c] * mat[o][col];
      mat[o][col] = 0;
    }
    r++;
  }
  for (int i = 0; i < N; i++) {
    assert(fabs(mat[i][i] - 1.) < EPS);
    for (int j = 0; j < N; j++)
      if (i != j) assert(fabs(mat[i][j]) < EPS);
  }
}
double tmat[mxT][mxT], tmp[mxT][mxT], res[mxT][mxT];
int T = 0;
vector<int> t;
void pow_mod(int power) {
  for (int i = 0; i < T; i++) res[i][i] = 1.;
  while (power) {
    if (power & 1) {
      for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) {
          tmp[i][j] = 0;
          for (int k = 0; k < T; k++) tmp[i][j] += tmat[i][k] * res[k][j];
        }
      for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) res[i][j] = tmp[i][j];
    }
    {
      for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) {
          tmp[i][j] = 0;
          for (int k = 0; k < T; k++) tmp[i][j] += tmat[i][k] * tmat[k][j];
        }
      for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) tmat[i][j] = tmp[i][j];
    }
    power >>= 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(8);
  cerr << fixed << setprecision(2);
  int M, K, u, v;
  cin >> N >> M >> K;
  t.push_back(0);
  T = 1;
  for (int i = 0; i < N; i++) cin >> dcr[i], T += dcr[i];
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    cnt[u][v]++;
    cnt[v][u]++;
  }
  for (int i = 0; i < N; i++) {
    if (dcr[i]) t.push_back(i);
    mat[i][i] = 1.;
    double r = 1. / g[i].size();
    for (auto j : g[i])
      if (!dcr[j]) mat[i][j] -= r;
  }
  gauss();
  for (int i = 0; i < T; i++) {
    u = t[i];
    assert(fabs(mat[u][u] - 1.) < EPS);
    for (int j = 0; j < T; j++) {
      v = t[j];
      tmat[i][j] += mat[u][v + N];
    }
  }
  if (K < 2) {
    cout << 0.0 << '\n';
    return 0;
  }
  pow_mod(K - 1);
  cout << res[0][T - 1] << '\n';
  return 0;
}
