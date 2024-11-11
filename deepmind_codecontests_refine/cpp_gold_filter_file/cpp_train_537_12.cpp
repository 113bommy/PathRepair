#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const long double EPS = 1e-8;
const long long MAXI = 20000;
const long long MOD = 16714589;
const long long MAXST = 2000;
const long long P = 40;
const long double PI = 3.14159265358979323;
long long a[105000], used[100500];
signed main() {
  long long t, n, k, d;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n >> k >> d;
    long long cnt = 0, ans = INF;
    for (long long j = 0; j < n; j++) {
      cin >> a[j];
      used[a[j]]++;
      if (used[a[j]] == 1) cnt++;
      if (j == d - 1) ans = cnt;
      if (j > d - 1) {
        used[a[j - d]]--;
        if (used[a[j - d]] == 0) cnt--;
        ans = min(ans, cnt);
      }
    }
    for (long long j = 0; j <= k; j++) used[j] = 0;
    if (ans == 0) ans++;
    cout << ans << endl;
  }
  return 0;
}
