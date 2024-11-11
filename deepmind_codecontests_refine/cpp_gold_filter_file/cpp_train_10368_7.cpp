#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> li;
long long solve(long long l1, long long l2) {
  if (l1 == 0) return (long long)1e18;
  long long y;
  long long d;
  long long cur = 0;
  for (int i = 0; i < li.size(); i++) {
    y = li[i] % l2;
    d = li[i] / l2;
    if (y == 0 || y + d >= l1) {
      cur += d;
      if (y != 0) cur++;
    } else
      return (long long)1e18;
  }
  return cur;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  long long x;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    li.push_back(x);
    ans += x;
  }
  sort(li.begin(), li.end());
  for (long long i = 1; i * i <= li[0]; i++) {
    ans = min(ans, solve(li[0] / i, li[0] / i + 1));
    ans = min(ans, solve((li[0] / i) - 1, (li[0] / i)));
    ans = min(ans, solve(i, i + 1));
    if (i > 1) ans = min(ans, solve(i - 1, i));
  }
  cout << ans << "\n";
  return 0;
}
