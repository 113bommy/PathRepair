#include <bits/stdc++.h>
using namespace std;
int const MAXN = (int)2e6 + 1, INF = (int)1e9 + 1, MOD = (int)1e9 + 7;
long long mypow(long long a, long long b, int mod) {
  long long rv = 1;
  while (b) {
    if (b % 2) rv = rv * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return rv;
}
bool ok, used[MAXN];
long long n, m, k, ans, l, r;
long long a[MAXN];
string second;
set<int> st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x, y, t;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  x = a[1];
  y = a[n];
  for (int i = 1; i <= n; i++) {
    if (a[i] > x && a[i] < y) {
      ans++;
      t = a[i];
    } else if (a[i] == x)
      l++;
    else
      r++;
  }
  if (ans == 0) {
    if (y - x <= 1) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << a[i] << " ";
      return 0;
    } else {
      cout << min(r, l) << endl;
      for (int i = 1; i <= min(r, l); i++) {
        a[i]++;
        a[n - i + 1]--;
      }
      for (int i = 1; i <= n; i++) cout << a[i] << " ";
      return 0;
    }
  }
  if (ans + max(r, l) - min(l, r) < r + l + ans % 2) {
    int i = 1;
    while (a[i] != t && a[n - i + 1] != t) {
      a[i] = t;
      a[n - i + 1] = t;
      i++;
    }
    cout << ans + max(r, l) - min(l, r) << endl;
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
  } else {
    int z = 0;
    cout << r + l + ans % 2 << endl;
    ans /= 2;
    ans *= 2;
    for (int i = 1; i <= n; i++) {
      if (a[i] > x && a[i] < y && z < ans / 2) {
        a[i] = x;
        z++;
      }
      if (a[i] > x && a[i] < y && z >= ans / 2 && z < ans) {
        a[i] = y;
        z++;
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
  }
  return 0;
}
