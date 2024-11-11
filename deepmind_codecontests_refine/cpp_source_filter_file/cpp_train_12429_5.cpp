#include <bits/stdc++.h>
using namespace std;
struct nes {
  long long x, y, t;
  double p;
};
nes a[100005];
long double dp[100005];
bool cmp(nes a, nes b) { return a.t < b.t; }
long long s(long long x) { return x * x; }
int main() {
  cout.precision(15);
  cout << fixed;
  long long n;
  long double sol = 0;
  cin >> n;
  for (long i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
  }
  sort(a + 1, a + n + 1, cmp);
  dp[1] = a[1].p;
  sol = dp[1];
  for (long i = 2; i <= n; i++) {
    for (long j = 1; j < i; j++) {
      if (s(a[i].x - a[j].x) + s(a[i].y - a[j].x) <= s(a[i].t - a[j].t)) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += a[i].p;
    sol = max(sol, dp[i]);
  }
  cout << sol << endl;
}
