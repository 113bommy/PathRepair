#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
int N, X;
pair<int, int> a[MM];
long long dp[2 * MM];
vector<int> p;
int main() {
  scanf("%d %d", &N, &X);
  p.push_back(X);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    p.push_back(a[i].first);
    p.push_back(a[i].second);
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  for (int i = 0; i < p.size(); i++) dp[i] = abs(p[i] - X);
  for (int i = 1; i <= N; i++) {
    long long best = dp[0] - p[0];
    for (int j = 0; j < p.size(); j++) {
      dp[j] = min(dp[j], p[j] + best);
      best = min(best, dp[j] - p[j]);
    }
    best = dp[p.size() - 1] + p.back();
    for (int j = p.size() - 1; j >= 0; j--) {
      dp[j] = min(dp[j], best - p[j]);
      best = min(best, dp[j] + p[j]);
    }
    for (int j = 0; j < p.size(); j++)
      if (p[j] < a[i].first || p[j] > a[i].second)
        dp[j] += min(abs(p[j] - a[i].first), abs(p[j] - a[i].second));
  }
  long long ans = dp[0];
  for (int i = 0; i < p.size(); i++) ans = min(ans, dp[i]);
  printf("%lld\n", ans);
}
