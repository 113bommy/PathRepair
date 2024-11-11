#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0; i < int(v.size()); i++) s << (i ? "," : "") << v[i];
  return s << '}';
}
template <typename S, typename T>
ostream& operator<<(ostream& s, pair<S, T> const& p) {
  return s << '(' << p.first << ',' << p.second << ')';
}
int N, R;
double dp[51][50001];
struct {
  int f, s;
  double p;
} L[50];
void calc() {
  double dp00 = dp[0][0];
  for (int t = 0; t < int(50001); t++) dp[N][t] = (t <= R) ? 0.0 : dp00;
  for (int n = int(N) - 1; n >= int(0); n--) {
    auto const& l = L[n];
    for (int t = int(50001) - 1; t >= int(0); t--) {
      double& ans = dp[n][t];
      {
        double ans1 = l.f + dp00;
        if (t + l.f <= 50000 && !isinf(dp[n + 1][t + l.f])) {
          ans1 = fmin(ans1, l.f + dp[n + 1][t + l.f]);
        }
        ans = l.p * ans1;
      }
      {
        double ans2 = (l.s + dp00);
        if (t + l.s <= 50000 && !isinf(dp[n + 1][t + l.s])) {
          ans2 = fmin(ans2, l.s + dp[n + 1][t + l.s]);
        }
        ans += (1.0 - l.p) * ans2;
      }
    }
  }
}
int main() {
  scanf("%d%d", &N, &R);
  for (int n = 0; n < int(N); n++) {
    auto& l = L[n];
    int p;
    scanf("%d%d%d", &l.f, &l.s, &p);
    l.p = 0.01 * p;
  }
  double a = 0.0, b = 1e7;
  for (int iter = 0; iter < int(80); iter++) {
    double c = 0.5 * (a + b);
    dp[0][0] = c;
    calc();
    if (dp[0][0] < c)
      b = c;
    else
      a = c;
  }
  printf("%.10f\n", 0.5 * (a + b));
}
