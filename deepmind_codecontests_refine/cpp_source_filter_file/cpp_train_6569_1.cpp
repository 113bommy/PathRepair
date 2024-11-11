#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, h;
  cin >> n >> h;
  vector<pair<long long, long long>> a;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    a.push_back(make_pair(x, y));
  }
  long long l = 0, r = 0;
  long long distance = h;
  long long result = h;
  long long height = 0;
  while (l < n) {
    while ((r < n) && (height <= h)) {
      if (r < n - 1) height += (-a[r].second + a[r + 1].first);
      distance += (a[r].second - a[r].first);
      r++;
    }
    if (distance > result) result = distance;
    if (l < n - 1) height -= (a[l + 1].first - a[l].second);
    distance -= (a[l].second - a[l].first);
    l++;
  }
  cout << result << endl;
}
