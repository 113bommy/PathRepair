#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
const int size = 1 << 8;
const double eps = 1e-10;
vector<double> T[size << 1];
vector<int> F[size << 1];
int n, q;
int A[MaxN], B[MaxN], f[MaxN];
double tt[MaxN];
inline int dcmp(double u, double v) {
  if (u - v > eps) return 1;
  if (v - u > eps) return -1;
  return 0;
}
inline double calc(int u, int v) { return (A[u] - A[v]) * 1.0 / (B[v] - B[u]); }
inline long long height(int v, int t) {
  return (long long)(A[v]) + (long long)(B[v]) * (long long)(t);
}
inline int calcans(int k, int u, int v, int t) {
  if ((k << 8) > u && ((k + 1) << 8) <= v) {
    int ans = upper_bound(T[k].begin(), T[k].end(), t * 1.0) - T[k].begin() - 1;
    return F[k][ans];
  }
  int ans = max(k << 8, u);
  for (int r = ans + 1; r <= v && r < ((k + 1) << 8); ++r)
    if (height(ans, t) < height(r, t)) ans = r;
  return ans;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int k = 0; k < n; ++k) scanf("%d %d", A + k, B + k);
  memset(f, -1, sizeof(f));
  for (int k = 0; k < n; ++k) {
    int t = k >> 8;
    for (int r = t << 8; r < ((t + 1) << 8) && r < n; ++r)
      if (A[k] >= A[r] && B[k] < B[r]) {
        double tmp = calc(k, r);
        if (dcmp(tmp, 0) < 0) continue;
        if (f[k] < 0 || dcmp(tmp, tt[k]) < 0 ||
            (dcmp(tmp, tt[k]) == 0 && B[r] > B[f[k]])) {
          tt[k] = tmp;
          f[k] = r;
        }
      }
  }
  for (int k = 0; k <= ((n - 1) >> 8); ++k) {
    T[k].clear(), F[k].clear();
    int tmp = k << 8;
    for (int r = (k << 8) + 1; r < ((k + 1) << 8) && r < n; ++r)
      if (make_pair(A[r], B[r]) > make_pair(A[tmp], B[tmp])) tmp = r;
    T[k].push_back(0);
    F[k].push_back(tmp);
    while (f[tmp] >= 0) {
      T[k].push_back(tt[tmp]);
      F[k].push_back(f[tmp]);
      tmp = f[tmp];
    }
    if (dcmp(T[k][T[k].size() - 1], 1e8) < 0) {
      T[k].push_back(1e8);
      F[k].push_back(F[k][F[k].size() - 1]);
    }
  }
  while (q--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    int ans = -1;
    --u;
    --v;
    for (int k = (u >> 8); k <= (v >> 8); ++k) {
      int cur = calcans(k, u, v, w);
      if (ans < 0 || height(ans, w) < height(cur, w)) ans = cur;
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
