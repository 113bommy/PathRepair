#include <bits/stdc++.h>
using namespace std;
int n, q;
int x[200], y[200];
int t[200], m[200];
bool done[200][200];
double mat[15][200][200];
double dp[200][200];
vector<vector<int>> vec;
bool col(int i, int j, int k) {
  return ((y[k] - y[j]) * (x[j] - x[i]) == (y[j] - y[i]) * (x[k] - x[j]));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> v;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      bool found = false;
      for (int k = 0; k < v.size(); ++k) {
        if (col(i, j, v[k][0])) {
          v[k].push_back(j);
          found = true;
          break;
        }
      }
      if (!found) {
        v.push_back(vector<int>(1, j));
      }
    }
    for (int j = 0; j < v.size(); ++j) {
      double cur = (1.0 / (double)v.size()) * (1.0 / (double)(v[j].size() + 1));
      for (int k : v[j]) mat[0][i][k] = cur;
      mat[0][i][i] += cur;
    }
  }
  cin >> q;
  for (int i = 0; i < q; ++i) cin >> t[i] >> m[i];
  for (int i = 0; i < q; ++i) {
    t[i]--;
    m[i]--;
  }
  for (int z = 0; z < 14; ++z) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          mat[z + 1][i][j] += mat[z][i][k] * mat[z][k][j];
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j || done[i][j]) continue;
      vector<int> v;
      v.push_back(i);
      v.push_back(j);
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j && col(i, j, k)) {
          v.push_back(k);
        }
      }
      for (int a : v)
        for (int b : v) done[a][b] = done[b][a] = true;
      vec.push_back(v);
    }
  for (int i = 0; i < q; ++i) {
    double best = 0.0;
    vector<double> v(n, 0.0);
    v[t[i]] = 1;
    vector<double> w;
    for (int z = 0; z < 15; ++z) {
      if ((m[i] & (1 << z)) == 0) continue;
      w = vector<double>(n, 0.0);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) w[i] += mat[z][i][j] * v[j];
      v = w;
    }
    for (vector<int> l : vec) {
      double cur = 0.0;
      for (int k : l) cur += (1.0 / (double)l.size()) * v[k];
      best = max(best, cur);
    }
    cout << setprecision(20) << best << "\n";
  }
}
