#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000005;
const long long INFLL = 1000000000000000002ll;
const long long MOD = 1000000007;
inline long long min(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
inline long long min(long long a, long long b, long long c, long long d) {
  return min(min(min(a, b), c), d);
}
inline long long max(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
inline long long max(long long a, long long b, long long c, long long d) {
  return max(max(max(a, b), c), d);
}
double DP[5005][5005];
enum { LEFT, RIGHT };
int X[5005], Y[5005], N;
double dist(int i, int j) {
  double dx = X[i] - X[j];
  double dy = Y[i] - Y[j];
  return sqrt(dx * dx + dy * dy);
}
double dp(int l, int r) {
  if (abs(l - r) <= 1) return 0;
  if (DP[l][r] > -1) return DP[l][r];
  double ret = 0;
  int n1 = min(l, r) + 1;
  int n2 = max(l, r) - 1;
  ret = max(ret, max(dp(l, n1), dp(n1, l)) + dist(l, n1));
  ret = max(ret, max(dp(r, n2), dp(n2, r)) + dist(l, n2));
  return DP[l][r] = ret;
}
int main() {
  cin >> N;
  for (int i = (0); i <= (5000); i++)
    for (int j = (0); j <= (5000); j++) DP[i][j] = -1;
  for (int i = (1); i <= (N); i++) scanf("%d %d", &X[i], &Y[i]);
  for (int i = (1); i <= (N); i++) X[i + N] = X[i];
  for (int i = (1); i <= (N); i++) Y[i + N] = Y[i];
  double ans = 0;
  for (int l = (1); l <= (N); l++)
    for (int r = (l + 1); r <= (l + N - 1); r++)
      ans = max(ans, max(dp(l, r), dp(r, l)) + dist(l, r));
  cout << setprecision(12) << fixed << ans;
}
