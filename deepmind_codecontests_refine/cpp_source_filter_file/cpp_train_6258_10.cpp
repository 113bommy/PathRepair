#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
inline int dcmp(double x) { return (x > eps) - (x < -eps); }
inline int dcmp(double a, double b) { return dcmp(a - b); }
template <int N, int M>
class matrix {
 public:
  double dat[N][M];
  void init() { memset(dat, 0, sizeof(dat)); }
  double *operator[](int p) { return dat[p]; }
  const double *operator[](const int &p) const { return dat[p]; }
  template <int X>
  friend matrix<N, M> operator*(const matrix<N, X> &A, const matrix<X, M> &B) {
    matrix<N, M> ret;
    ret.init();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < X; j++) {
        if (A[i][j]) {
          for (int k = 0; k < M; k++) {
            ret[i][k] += A[i][j] * B[j][k];
          }
        }
      }
    }
    return ret;
  }
};
int n, a[100010], b[100010];
double p[100010], pos[100010];
class line {
 public:
  double a, b;
  int id;
  bool operator<(const line &t) const {
    if (dcmp(a, t.a) == 0) return dcmp(b, t.b) == 1;
    return dcmp(a, t.a) == -1;
  }
} l[100010], stk[100010];
inline double intersect(const line &A, const line &B) {
  return (B.b - A.b) / (A.a - B.a);
}
long long t;
int top = 0;
matrix<3, 3> trans, pw[40];
void init() {
  pw[0] = trans;
  for (int i = 1; i < 35; i++) pw[i] = pw[i - 1] * pw[i - 1];
}
matrix<3, 3> getpw(long long val) {
  matrix<3, 3> ret;
  ret.init();
  ret[0][0] = ret[1][1] = ret[2][2] = 1;
  for (int i = 0; i < 35; i++)
    if ((val >> i) & 1) ret = ret * pw[i];
  return ret;
}
int main() {
  scanf("%d%lld", &n, &t);
  t--;
  double M = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d%d%lf", &a[i], &b[i], &p[i]), M = max(M, b[i] * p[i]);
  for (int i = 1; i <= n; i++) l[i] = (line){p[i], p[i] * a[i], i};
  sort(l + 1, l + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i != 1 && dcmp(l[i].a, stk[top].a) == 0) continue;
    while (top >= 2 && dcmp(intersect(stk[top - 1], stk[top]),
                            intersect(stk[top], l[i])) != -1)
      top--;
    stk[++top] = l[i];
  }
  pos[1] = -1e15;
  for (int i = 1; i < top; i++) pos[i + 1] = intersect(stk[i + 1], stk[i]);
  pos[top + 1] = 1e15;
  matrix<1, 3> ans;
  ans[0][0] = 0;
  ans[0][1] = 0;
  ans[0][2] = 1;
  long long cur = 0;
  for (int i = 1; i <= top; i++) {
    if (dcmp(cur * M - ans[0][0], pos[i + 1]) != -1) continue;
    int C = stk[i].id;
    trans[0][0] = 1 - p[C];
    trans[1][0] = p[C] * M;
    trans[2][0] = p[C] * a[C];
    trans[1][1] = trans[2][1] = trans[2][2] = 1;
    init();
    long long L = cur, R = t, ppos = -1;
    while (L <= R) {
      long long mid = (L + R) >> 1;
      matrix<1, 3> tmp = ans * getpw(mid - cur);
      if (dcmp(cur * M - tmp[0][0], pos[i + 1]) == -1)
        ppos = mid, L = mid + 1;
      else
        R = mid - 1;
    }
    if (ppos >= cur) {
      ans = ans * getpw(ppos - cur + 1);
      cur = ppos + 1;
    }
  }
  printf("%.10lf\n", ans[0][0]);
  return 0;
}
