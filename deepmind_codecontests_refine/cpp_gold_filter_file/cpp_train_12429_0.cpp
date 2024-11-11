#include <bits/stdc++.h>
using namespace std;
double dp[1005];
bool seen[1005];
int n;
long long X[1005], Y[1005], T[1005];
double P[1005];
long long getDist(int i, int j) {
  long long dx = X[i] - X[j];
  long long dy = Y[i] - Y[j];
  return dx * dx + dy * dy;
}
double solve(int idx) {
  double& ref = dp[idx];
  if (seen[idx]) return ref;
  ref = 0;
  seen[idx] = true;
  for (int i = 0; i < n; i++)
    if (T[i] > T[idx]) {
      if (((T[i] - T[idx]) * (T[i] - T[idx])) >= getDist(i, idx))
        ref = max(ref, solve(i));
    }
  ref += P[idx];
  return ref;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> X[i] >> Y[i] >> T[i] >> P[i];
  double res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, solve(i));
  }
  printf("%.8lf\n", res);
  return 0;
}
