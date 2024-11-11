#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i) {
    if (i != v.begin()) os << ", ";
    os << *i;
  }
  os << "]";
  return os;
}
vector<vector<double> > multiply(const vector<vector<double> >& A,
                                 const vector<vector<double> >& B) {
  int n = ((int)((A).size()));
  vector<vector<double> > R(n, vector<double>(n, 0));
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(n); ++j)
      for (int k = 0; k < (int)(n); ++k) R[i][j] += A[i][k] * B[k][j];
  return R;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<bool> is_trap(n);
  for (int i = 0; i < (int)(n); ++i) {
    int x;
    scanf("%d", &x);
    is_trap[i] = (x == 1);
  }
  vector<vector<int> > G(n);
  for (int i = 0; i < (int)(m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<vector<double> > D(n, vector<double>(2 * n, 0));
  for (int i = 0; i < (int)(n); ++i) {
    D[i][i] = ((int)((G[i]).size()));
    for (__typeof((G[i]).begin()) j = (G[i]).begin(); j != (G[i]).end(); ++j)
      if (is_trap[*j]) {
        D[i][n + *j] -= 1;
      } else {
        D[i][*j] -= 1;
      }
  }
  int rank = 0;
  const double EPS = 1e-9;
  for (int i = 0; i < (int)(n); ++i) {
    int best = rank;
    for (int j = (int)(rank); j <= (int)(n - 1); ++j)
      if (abs(D[j][i]) > abs(D[best][i])) best = j;
    if (abs(D[best][i]) < EPS) continue;
    for (int k = 0; k < (int)(2 * n); ++k) swap(D[rank][k], D[best][k]);
    for (int k = (int)(2 * n - 1); k >= (int)(i); --k) D[rank][k] /= D[rank][i];
    for (int j = (int)(rank + 1); j <= (int)(n - 1); ++j)
      if (abs(D[j][i]) >= EPS)
        for (int k = (int)(2 * n - 1); k >= (int)(i); --k)
          D[j][k] -= D[j][i] * D[rank][k];
    ++rank;
  }
  assert(rank == n);
  int cnt = 0;
  vector<int> mapping(n, -1);
  for (int i = 0; i < (int)(n); ++i)
    if (i == 0 || is_trap[i]) mapping[i] = cnt++;
  vector<vector<double> > M(cnt, vector<double>(cnt, 0));
  for (int t = 0; t < (int)(n); ++t)
    if (is_trap[t]) {
      vector<double> P(n, 0);
      for (int i = (int)(n - 1); i >= (int)(0); --i) {
        P[i] -= D[i][n + t];
        for (int j = (int)(i + 1); j <= (int)(n - 1); ++j)
          P[i] -= D[i][j] * P[j];
      }
      for (int i = 0; i < (int)(n); ++i)
        if (mapping[i] != -1) M[mapping[t]][mapping[i]] = P[i];
    }
  --k;
  vector<vector<double> > R(cnt, vector<double>(cnt, 0));
  for (int i = 0; i < (int)(cnt); ++i) R[i][i] = 1;
  while (k > 0) {
    if (k % 2) R = multiply(R, M);
    M = multiply(M, M);
    k /= 2;
  }
  printf("%.9lf\n", R[cnt - 1][0]);
}
