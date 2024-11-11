#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
bool isP(long long n) {
  if (n == 2LL) return 1;
  if (n % 2LL == 0LL)
    return 0;
  else if (n == 1)
    return 0;
  for (long long i = 3; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  long long ans = 1;
  long long x = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= x) {
      ans++;
      x++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
