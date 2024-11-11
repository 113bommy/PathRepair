#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795029L;
int K, X0, Y0;
double eps;
vector<int> X, Y;
bool f(double R) {
  int n = (int)X.size();
  vector<double> P(n);
  for (int i = 0; i < n; i++) {
    double D = hypot(X[i] - X0, Y[i] - Y0);
    P[i] = D <= R ? 1 : exp(1 - (D * D) / (R * R));
  }
  vector<vector<double> > dp(n, vector<double>(K + 1, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= K; j++) {
      if (!j)
        dp[i][j] = 1;
      else if (!i)
        dp[i][j] = j == 1 ? P[i] : 0;
      else
        dp[i][j] = P[i] * dp[i - 1][j - 1] + (1 - P[i]) * dp[i - 1][j];
    }
  return dp[n - 1][K] >= eps;
}
double search() {
  double from = 0, to = 10000;
  for (int i = 0; i < 1000; i++) {
    double mid = (from + to) / 2;
    if (f(mid))
      to = mid;
    else
      from = mid;
  }
  return (from + to) / 2;
}
bool solve(int testNumber) {
  int n;
  if (scanf("%d", &n) == EOF) return false;
  scanf("%d %lf", &K, &eps);
  eps = 1 - eps / 1000;
  scanf("%d %d", &X0, &Y0);
  X.resize(n);
  Y.resize(n);
  for (int i = 0; i < n; i++) scanf("%d %d", &X[i], &Y[i]);
  printf("%.12f\n", search());
  return true;
}
int main() {
  for (int i = 1; solve(i); i++)
    ;
  return 0;
}
