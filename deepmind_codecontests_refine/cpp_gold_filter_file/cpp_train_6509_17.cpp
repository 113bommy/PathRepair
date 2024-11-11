#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXK = 55;
int n, k;
int t[MAXN];
long long sum[MAXN];
double rev[MAXN];
double pre[MAXN];
double dp[MAXN][MAXK];
vector<double> M, B, border;
bool doubleEqual(double a, double b) { return fabs(a - b) < 1e-8; }
bool doubleLess(double a, double b) { return a < b && !doubleEqual(a, b); }
bool bad(int i, int j, int k) {
  return doubleLess((B[k] - B[i]) * (M[i] - M[j]),
                    (B[j] - B[i]) * (M[i] - M[k]));
}
double intersectPoint(int i, int j) { return (B[j] - B[i]) / (M[i] - M[j]); }
const double inf = 1e12;
void append(double m, double b) {
  M.push_back(m);
  B.push_back(b);
  if (M.size() == 1)
    border.push_back(-inf);
  else
    border.push_back(intersectPoint(M.size() - 2, M.size() - 1));
  while (M.size() > 2 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
    M.erase(M.end() - 2);
    B.erase(B.end() - 2);
    border.erase(border.end() - 2);
    border[border.size() - 1] = intersectPoint(M.size() - 2, M.size() - 1);
  }
}
double query(double x) {
  int l = 0, r = M.size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (doubleLess(x, border[mid]))
      r = mid;
    else
      l = mid;
  }
  return M[l] * x + B[l];
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &t[i]);
  sum[0] = 0;
  rev[0] = 0;
  pre[0] = 0;
  for (int i = 1; i < n + 1; ++i) {
    sum[i] = sum[i - 1] + t[i];
    rev[i] = rev[i - 1] + 1.0 / t[i];
    pre[i] = pre[i - 1] + (double)sum[i] / t[i];
  }
  dp[0][0] = 0;
  for (int i = 0; i < n + 1; ++i) {
    dp[i][1] = pre[i];
  }
  for (int j = 2; j < k + 1; ++j) {
    M.clear();
    B.clear();
    border.clear();
    for (int i = j; i <= n; ++i) {
      append(-sum[i - 1],
             dp[i - 1][j - 1] - pre[i - 1] + rev[i - 1] * sum[i - 1]);
      dp[i][j] = pre[i] + query(rev[i]);
    }
  }
  printf("%.15f\n", dp[n][k]);
}
int main() {
  solve();
  return 0;
}
