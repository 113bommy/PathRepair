#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > a(n), b(m);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
  vector<long long> ans(1000005);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i].first > b[j].first || a[i].second > b[i].second) continue;
      long long x = b[j].first - a[i].first;
      long long diff = b[j].second - a[i].second + 1;
      ans[x] = max(ans[x], diff);
    }
  }
  for (long long i = 1000001; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  long long min1 = 1e7;
  for (long long i = 0; i <= 1000001; i++) {
    min1 = min(min1, ans[i] + i);
  }
  cout << min1 << endl;
  return 0;
}
