#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
long long int binpow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
vector<long long int> ans(101, -1);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tc = 1;
  while (tc--) {
    long long int x, y, k;
    cin >> x >> y >> k;
    long long int ans = x * y - 2 * (k - 1);
    bool f = 1;
    bool g = 0;
    long long int i = 1;
    long long int j = 1;
    while (k > 1) {
      if (g == 0) {
        cout << 2 << " " << i << " " << j << " ";
        g = 1;
      } else {
        cout << i << " " << j << "\n";
        g = 0;
        k--;
      }
      if (f) {
        if (j == y) {
          i++;
          f = 0;
          continue;
        }
        j++;
      } else {
        if (j == 1) {
          i++;
          f = 1;
          continue;
        }
        j--;
      }
    }
    cout << ans << " ";
    while (i <= x) {
      cout << i << " " << j << " ";
      if (f) {
        if (j == y) {
          i++;
          f = 0;
        } else
          j++;
      } else {
        if (j == 1) {
          i++;
          f = 1;
        } else
          j--;
      }
    }
  }
  return 0;
}
