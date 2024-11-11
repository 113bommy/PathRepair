#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
const double eps = 1e-10, INF = 1.0 * 1e13;
const int N = 55;
int n;
long long a[N], b[N], cnt[N], sum[N];
double f[N][N], pre[N][N];
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct data {
  long long a;
  double b;
  bool operator<(const data &rhs) const {
    if (a != rhs.a) return a < rhs.a;
    return b < rhs.b;
  }
} A[N], B[N];
bool check(double mid) {
  memset(cnt, 0, sizeof cnt);
  memset(pre, 0, sizeof pre);
  double res = 0;
  for (int i = 1; i <= n; ++i) A[i] = (data){a[i], a[i] - mid * b[i]};
  sort(A + 1, A + 1 + n);
  int tp = 0;
  for (int i = 1, j = 1; i <= n; i = j + 1, j = i) {
    while (j + 1 <= n && A[j + 1].a == A[j].a) ++j;
    cnt[++tp] = j - i + 1;
    sum[tp] = sum[tp - 1] + cnt[tp];
    for (int k = 1; k <= cnt[tp]; ++k)
      pre[tp][k] = pre[tp][k - 1] + A[i + k - 1].b;
  }
  for (int i = 0; i <= n; ++i) fill(f[i], f[i] + n + 1, INF);
  f[0][0] = 0;
  for (int i = 1; i <= tp; ++i) {
    for (int j = 0; j <= sum[i - 1]; ++j)
      for (int k = 0; k <= cnt[i]; ++k)
        Min(f[i][max(j - k, 0) + (cnt[i] - k)], f[i - 1][j] + pre[i][k]);
  }
  return dcmp(f[tp][0]) <= 0;
}
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) a[i] = gi();
  for (int i = 1; i <= n; ++i) b[i] = gi();
  double l = 0, r = 1.0 * 5e9;
  int cnt = 60;
  while (r - l > eps && cnt) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
    --cnt;
  }
  printf("%.0lf\n", l * 1000);
  return 0;
}
