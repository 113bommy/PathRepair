#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 1LL;
  cin >> n;
  vector<pair<long long, long long> > d(n + 1);
  for (int i = 1; i <= n; i++) cin >> d[i].first >> d[i].second;
  for (int i = 1; i <= n; i++) {
    if (d[i - 1].first == d[i - 1].second) d[i - 1].first++, d[i - 1].second++;
    if (max(d[i].first, d[i].second) - min(d[i - 1].first, d[i - 1].second) +
            1 >
        0)
      ans += max(d[i].first, d[i].second) -
             min(d[i - 1].first, d[i - 1].second) + 1;
  }
  cout << ans << '\n';
}
