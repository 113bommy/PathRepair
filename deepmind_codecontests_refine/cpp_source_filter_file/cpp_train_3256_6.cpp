#include <bits/stdc++.h>
using namespace std;
long long t;
bool vis[1000005];
vector<long long> prms;
long long prefp[1000005];
const long long M = 1e9 + 7;
long long fspow(long long x, long long y) {
  long long ans;
  if (y == 0) return 1;
  ans = fspow(x, y / 2);
  if (y % 2 == 0) return ((ans * ans) % M);
  return (x * ((ans * ans) % M)) % M;
}
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(x % y, y);
}
long long p2(long long x) {
  long long ans = 0;
  while (x > 1) {
    ans++;
    x /= 2;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  long long ans = prefp[n];
  long long cnt = 1;
  while (1) {
    if (prms[cnt] * prms[cnt] <= n)
      ans--;
    else
      break;
    cnt++;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  cin >> t;
  for (long long i = 2; i <= 1e6; i++) {
    if (vis[i]) {
      prefp[i] = prms.size();
      continue;
    }
    prms.push_back(i);
    long long cnt = 2 * i;
    while (cnt <= 1e6) {
      vis[cnt] = 1;
      cnt += i;
    }
    prefp[i] = prms.size();
  }
  while (t--) solve();
}
