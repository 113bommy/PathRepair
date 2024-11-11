#include <bits/stdc++.h>
using namespace std;
vector<int> ans, pr(1001);
double dp[1001], x[1001], b[1001], cr = 0, od;
int n;
bool check(double r) {
  for (int i = 0; i < 1001; ++i) dp[i] = INT_MAX;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (sqrt(abs(od - x[i] + x[j])) - b[i] * r + dp[j] < dp[i]) {
        dp[i] = sqrt(abs(od - x[i] + x[j])) - b[i] * r + dp[j];
        pr[i] = j;
      }
    }
  }
  if (dp[n] < 0.0) return true;
  if (r < cr) return false;
  cr = r;
  ans.clear();
  int curr = n;
  while (curr != 0) {
    ans.push_back(curr);
    curr = pr[curr];
  }
  reverse(ans.begin(), ans.end());
  return false;
}
void bs() {
  double l = 0, r = INT_MAX, mid;
  while (r - l > 1e-8) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
}
int main() {
  dp[0] = 0;
  x[0] = 0;
  b[0] = 0;
  scanf("%d %lf", &n, &od);
  for (int i = 1; i <= n; ++i) scanf("%lf %lf", &x[i], &b[i]);
  bs();
  for (auto it : ans) printf("%d ", it);
  return 0;
}
