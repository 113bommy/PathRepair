#include <bits/stdc++.h>
using namespace std;
const int mxN = 5e4 + 7;
const int inf = 1e5 + 7;
const long long mod = 1e5 + 7;
const long long infll = 1e18 + 7;
long long a[mxN], b[mxN];
map<long long, bool> mp;
int n;
bool check = false;
bool ok(long long x) {
  for (int i = 1; i <= n; i++) a[i] = b[i];
  mp.clear();
  for (int i = 1; i <= n; i++) {
    if (a[i] <= x) {
      if (mp[a[i]] == true) {
        while (mp[a[i]] == true && a[i] != 1) {
          a[i] /= 2;
        }
        if (mp[a[i]] == true) return false;
      }
      mp[a[i]] = true;
    } else {
      while ((a[i] > x || mp[a[i]] == true) && a[i] != 1) {
        a[i] /= 2;
      }
      if (mp[a[i]] == true) return false;
      mp[a[i]] = true;
    }
    if (check == true) cout << a[i] << ' ';
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) b[i] = a[i];
  long long l = 0;
  long long r = infll;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    if (ok(m))
      r = m;
    else
      l = m;
  }
  check = true;
  ok(r);
  return 0;
}
