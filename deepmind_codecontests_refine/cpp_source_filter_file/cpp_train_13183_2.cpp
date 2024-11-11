#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long siz = 1e5 + 10;
const long long base = 32;
const long long MAXX = 1e18;
long long res[20][2][2][(1 << 18)];
long long n, m;
vector<long long> x, y;
long long Po[siz];
long long dp(long long pos, bool sta, bool lar, long long mask) {
  if (pos >= n) {
    return (mask == ((1 << n) - 1)) ? 0 : -MAXX;
  }
  long long &ans = res[pos][sta][lar][mask];
  if (ans != -1) {
    return ans;
  }
  ans = -MAXX;
  for (long long i = 0; i < n; i++) {
    if (lar) {
      if ((mask & (1 << i)) != 0) {
        continue;
      }
      if (sta && (x[i] == 0)) {
        continue;
      }
      ans =
          max(ans, x[i] * Po[n - pos - 1] + dp(pos + 1, 1, 1, mask | (1 << i)));
    } else {
      if (((mask & (1 << i)) != 0) || (x[i] > y[pos])) {
        continue;
      }
      if (sta && (x[i] == 0)) {
        continue;
      }
      ans = max(ans, x[i] * Po[n - pos - 1] +
                         dp(pos + 1, 1, (x[i] < y[pos]), mask | (1 << i)));
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  while (n) {
    x.push_back(n % 10);
    n /= 10;
  }
  while (m) {
    y.push_back(m % 10);
    m /= 10;
  }
  Po[0] = 1;
  for (long long i = 1; i <= 18; i++) {
    Po[i] = Po[i - 1] * 10;
  }
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  n = (int)x.size();
  m = (int)y.size();
  if (n < m) {
    sort(x.begin(), x.end());
    for (long long i = n - 1; i >= 0; i--) {
      cout << x[i];
    }
    cout << '\n';
    return 0;
  }
  memset(res, -1, sizeof(res));
  cout << dp(0, 0, 0, 0) << '\n';
  return 0;
}
