#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<long long> even_sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    even_sum[i] = even_sum[i - 1];
    if (i % 2) even_sum[i] += a[i];
  }
  if (n == 1) {
    cout << a[1] << '\n';
    return;
  }
  vector<int> b(1, 0);
  for (int i = 2; i <= n; i += 2) b.push_back(a[i] - a[i - 1]);
  long long ans = b[1], sum = 0;
  for (size_t r = 1; r < b.size(); ++r) {
    sum += b[r];
    ans = max(ans, sum);
    sum = max(sum, 0ll);
  }
  long long best = even_sum[n] + max(ans, 0ll);
  if (n > 2) {
    vector<int> c(1, 0);
    for (size_t i = 3; i < a.size(); i += 2) c.push_back(a[i - 1] - a[i]);
    ans = c[1], sum = 0;
    for (size_t r = 1; r < c.size(); ++r) {
      sum += c[r];
      ans = max(ans, sum);
      sum = max(sum, 0ll);
    }
    best = max(best, even_sum[n] + ans);
  }
  cout << best << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
