#include <bits/stdc++.h>
using namespace std;
long long x;
vector<pair<long long, long long> > ans;
int main() {
  cin >> x;
  x *= 6;
  for (long long n = 1; n <= 2000000; n++) {
    long long t = n * (n + 1);
    if (x % t) continue;
    long long y = x / t - n - n - 1;
    if (y < 0 || y % 3) continue;
    y /= 3;
    ans.push_back(pair<long long, long long>(n, n + y));
    if (y) ans.push_back(pair<long long, long long>(n + y, n));
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++)
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  return 0;
}
