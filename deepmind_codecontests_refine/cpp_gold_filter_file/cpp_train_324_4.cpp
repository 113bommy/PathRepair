#include <bits/stdc++.h>
long long mod(long long x) {
  if (x < 0) return -x;
  return x;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = x * x;
  }
  return res;
}
using namespace std;
const int MAXN = 500005;
vector<long long> v;
long long a[1000000], b[1000000];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, t, m, k, x = 0, y = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> t;
    a[i] = t;
    if (t % 2 == 0) {
      x++;
    } else {
      y++;
    }
  }
  long long ans = 0;
  sort(a, a + n);
  if (x == y || x == y - 1 || x == y + 1) {
    cout << "0";
    return 0;
  } else {
    if (x > y) {
      x = x - y - 1;
      for (long long i = 0; i < n && x > 0; i++) {
        if (a[i] % 2 == 0) {
          ans += a[i];
          x--;
        }
      }
    } else {
      y = y - x - 1;
      for (long long i = 0; i < n && y > 0; i++) {
        if (a[i] % 2 == 1) {
          ans += a[i];
          y--;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
