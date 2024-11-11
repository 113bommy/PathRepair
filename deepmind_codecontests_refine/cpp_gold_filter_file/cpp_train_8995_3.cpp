#include <bits/stdc++.h>
using namespace std;
int coef[][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0},
                 {0, 0, 0, 1, 0, 1}, {3, 1, 1, 1, 2, 1}, {3, 1, 1, 1, 1, 2}};
int N = 6;
int n, sx, sy, dx, dy;
long long T;
vector<vector<int> > coefMatrix() {
  vector<vector<int> > mat(N);
  for (int i = 0; i < N; i++) {
    mat[i].resize(N);
    for (int j = 0; j < N; j++) mat[i][j] = coef[i][j];
  }
  return mat;
}
vector<vector<int> > operator*(const vector<vector<int> >& a,
                               const vector<vector<int> >& b) {
  vector<vector<int> > ret(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ret[i][j] = 0;
      for (int k = 0; k < N; k++) {
        ret[i][j] += 1LL * a[i][k] * b[k][j] % n;
        ret[i][j] %= n;
      }
    }
  }
  return ret;
}
vector<vector<int> > operator^(const vector<vector<int> >& base,
                               long long power) {
  if (power == 1) return base;
  vector<vector<int> >&& ret = base ^ (power >> 1);
  ret = ret * ret;
  if (power & 1) ret = ret * base;
  return ret;
}
vector<int> operator*(const vector<vector<int> >& mat, const vector<int>& v) {
  vector<int> ret(v.size());
  for (int i = 0; i < ret.size(); i++) {
    ret[i] = 0;
    for (int j = 0; j < v.size(); j++) {
      ret[i] += 1LL * v[j] * mat[i][j] % n;
      ret[i] %= n;
    }
  }
  return ret;
}
int main() {
  int c, c2;
  scanf("%d%d%d%d%d%I64d", &n, &sx, &sy, &dx, &dy, &T);
  if (T == 0) {
    printf("%d %d\n", sx, sy);
    return 0;
  }
  sx--;
  sy--;
  vector<vector<int> >&& mat = coefMatrix() ^ T;
  vector<int> v = {
      1, 0, sx, sy, (dx + sx + sy + 2) % n, (dy + sx + sy + 2) % n};
  vector<int> ret = mat * v;
  printf("%d %d\n", (ret[2] + n) % n + 1, (ret[3] + n) % n + 1);
  return 0;
}
