#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int N, K, epsilon, X[105], Y[105];
double dp[105];
template <class T>
void read(T& x) {
  x = 0;
  int f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 - '0' + ch;
    ch = getchar();
  }
  x *= f;
}
bool judge(double x) {
  for (int i = 0; i <= N; i++) dp[i] = 0;
  dp[0] = 1;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    double d = (X[i] - X[0]) * (X[i] - X[0]) + (Y[i] - Y[0]) * (Y[i] - Y[0]);
    if (d <= x * x)
      cnt++;
    else {
      double p = exp(1 - d / (x * x));
      for (int j = N; j >= 1; j--) {
        dp[j] = dp[j] * (1 - p) + dp[j - 1] * p;
      }
    }
  }
  if (cnt >= K) return 1;
  for (int i = K - cnt; i <= N; i++)
    if (dp[i] >= (1 - double(epsilon) / 1000.0)) return 1;
  return dp[K - cnt] >= (1 - double(epsilon) / 1000.0);
}
double solve() {
  double l = eps, r = 4000, ans = 4000;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (judge(mid))
      r = mid, ans = mid;
    else
      l = mid;
  }
  return ans;
}
int main() {
  read(N);
  read(K), read(epsilon);
  int flag = 0;
  for (int i = 0; i <= N; i++) {
    read(X[i]), read(Y[i]);
    if (i != 0 && X[i] == X[0] && Y[i] == Y[0]) flag++;
  }
  if (flag >= K)
    printf("%.17lf\n", 0.0);
  else
    printf("%.17lf\n", solve());
  return 0;
}
