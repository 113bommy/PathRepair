#include <bits/stdc++.h>
using namespace std;
long long int n, k, a[100007];
pair<long long int, long long int> cur[1007];
bool res[200001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long int i = 1; i <= n; ++i) cin >> a[i];
  long long int last = 0, cnt = 0;
  for (long long int t = 0; t <= 150000; ++t) {
    for (long long int i = 1; i <= k; ++i) {
      if (a[cur[i].second] == cur[i].first) {
        if (cur[i].second <= n && cur[i].second >= 1) cnt++;
        cur[i].second = ++last;
        cur[i].first = 0;
      }
    }
    long long int d = round((100.0 * cnt) / (1.0 * n));
    for (long long int i = 1; i <= k; ++i) {
      if (cur[i].second <= n && cur[i].second >= 1 && cur[i].first + 1 == d)
        res[cur[i].second] = 1;
      cur[i].first++;
    }
  }
  long long int sum = 0;
  for (long long int i = 1; i <= n; ++i) sum += res[i];
  cout << sum << '\n';
  return 0;
}
