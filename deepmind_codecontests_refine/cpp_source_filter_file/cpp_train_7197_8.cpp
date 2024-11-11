#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > pr(n);
  for (int i = 0; i < n; i++) cin >> pr[i].first >> pr[i].second;
  long long ans = 0;
  long long x = 0;
  long long y = 0;
  for (int i = 1; i < n; i++) {
    ans += max(0LL, min(pr[i].first, pr[i].second) -
                        max(pr[i - 1].first, pr[i - 1].second) + 1);
    if (pr[i].first == pr[i].second) ans--;
  }
  cout << ans + min(pr[0].first, pr[0].second) + 1;
  return 0;
}
