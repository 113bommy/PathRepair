#include <bits/stdc++.h>
using namespace std;
long long n, pr;
pair<long long, long long> ara[100010];
long long cnt[100010];
int main() {
  std::ios_base::sync_with_stdio(false);
  ;
  cin >> n >> pr;
  for (int i = 1; i <= n; i++) {
    cin >> ara[i].first >> ara[i].second;
  }
  ara[0] = ara[n];
  ara[n + 1] = ara[n];
  for (int i = 0; i <= n + 1; i++) {
    long long a = ara[i].first / pr;
    long long b = ara[i].second / pr;
    if (ara[i].first % pr) {
      a++;
    }
    cnt[i] = max(0LL, b - a + 1);
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double r1, r2, prob;
    r1 = ara[i - 1].second - ara[i - 1].first + 1;
    r2 = ara[i].second - ara[i].first + 1;
    prob = r1 * r2;
    ans += (cnt[i] / prob) * 1000.0 * (r1 - cnt[i]) * 2.0;
    r1 = ara[i].second - ara[i].first + 1;
    r2 = ara[i + 1].second - ara[i + 1].first + 1;
    prob = r1 * r2;
    ans += (cnt[i] / prob) * 1000.0 * r2 * 2.0;
  }
  cout << fixed << setprecision(7) << ans;
  return 0;
}
