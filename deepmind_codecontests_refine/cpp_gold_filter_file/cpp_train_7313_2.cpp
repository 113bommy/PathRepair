#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const long double PI = acos(-1);
long long t, k, n;
long long a[N], mini[N];
long long cmp(long long a[], long long b[]) {
  if (a[0] != b[0]) return a[0] > b[0] ? 1 : -1;
  long long i = a[0];
  while (a[i] == b[i] && i > 0) i--;
  if (i == 0) return 0;
  return a[i] > b[i] ? 1 : -1;
}
void cpy(long long a[], long long b[]) {
  for (long long i = 0; i <= b[0]; i++) a[i] = b[i];
}
void Test() {
  long long l, cnt, s, rem, y, z, act, i, j, d;
  cin >> n >> k;
  mini[0] = 1000;
  for (i = 1; i <= 1000; i++) mini[i] = 9;
  for (l = 0; l <= 9; l++) {
    if (l + k >= 10) {
      act = 9 - l + 1;
      y = act;
      z = (l + k) % 10 + 1;
    } else {
      act = k + 1;
      y = act;
    }
    s = 0;
    for (i = 0; i <= k; i++) s += (l + i) % 10;
    for (cnt = 0; cnt * 9 * act <= n - s; cnt++) {
      rem = n - s - cnt * 9 * act;
      if (l + k >= 10) {
        if ((rem - z) % (y + z)) continue;
        d = (rem - z) / (y + z);
      } else {
        if (rem % y) continue;
        d = rem / y;
      }
      a[0] = 0;
      a[++a[0]] = l;
      for (j = 1; j <= cnt; j++) a[++a[0]] = 9;
      if (d < 9) {
        if (d) a[++a[0]] = d;
      } else {
        a[++a[0]] = 8;
        d -= 8;
        for (j = 1; j <= d / 9; j++) a[++a[0]] = 9;
        if (d % 9) a[++a[0]] = d % 9;
      }
      if (cmp(a, mini) == -1) cpy(mini, a);
    }
  }
  if (mini[0] == 1000) return cout << -1 << '\n', void();
  for (i = mini[0]; i >= 1; i--) cout << mini[i];
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) Test();
  return 0;
}
