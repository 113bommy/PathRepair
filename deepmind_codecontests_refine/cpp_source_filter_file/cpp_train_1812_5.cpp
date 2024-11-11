#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
long long raichu(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
bool isprime(long long n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  else {
    long long z = sqrt(n);
    for (int i = 0; i < z - 1; i++)
      if (n % (i + 2) == 0) return false;
    return true;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, T;
  T = t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<int, pair<int, int> > > ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '.') continue;
        int r = min(min(n - i - 1, i), min(m - j - 1, j));
        for (int p = 1; p <= r; p++) {
          if (v[i - p][j] == '*' && v[i + p][j] == '*' && v[i][j - p] == '*' &&
              v[i][j + p] == '*') {
            ans.push_back(make_pair(r, make_pair(i, j)));
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    if ((int)ans.size() < k)
      cout << -1 << endl;
    else {
      cout << ans[k - 1].second.first + 1 << " " << ans[k - 1].second.second + 1
           << endl;
      cout << ans[k - 1].second.first - ans[k - 1].first + 1 << " "
           << ans[k - 1].second.second + 1 << endl;
      cout << ans[k - 1].second.first + ans[k - 1].first + 1 << " "
           << ans[k - 1].second.second + 1 << endl;
      cout << ans[k - 1].second.first + 1 << " "
           << ans[k - 1].second.second - ans[k - 1].first + 1 << endl;
      cout << ans[k - 1].second.first + 1 << " "
           << ans[k - 1].second.second + ans[k - 1].first + 1 << endl;
    }
  }
  return 0;
}
