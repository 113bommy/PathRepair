#include <bits/stdc++.h>
using namespace std;
const int areTests = 0, N = 3e3 + 20;
long long n, a[N], dp[N];
set<long long> s;
void run_test(int testcase) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i;
    s.insert(a[i]);
  }
  vector<long long> v(s.begin(), s.end());
  for (int j = 0; j < v.size(); j++) {
    dp[j] = abs(v[j] - a[0]);
  }
  for (int i = 1; i < n; i++) {
    for (long long j = 0, mn = LLONG_MAX; j < v.size(); j++) {
      mn = min(mn, dp[j]);
      dp[j] = mn + abs(v[j] - a[i]);
    }
  }
  cout << *min_element(dp, dp + v.size());
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t = 1;
  if (areTests) cin >> t;
  for (int i = 1; i <= t; i++) {
    run_test(i);
  }
}
