#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
const int N = 1e6 + 40;
const int MAXK = 12;
const long long int INF = 1000000000000000000;
const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
long long int expo_pow(long long int x, long long int y) {
  if (y == 0) return 1;
  y = y % ((1000000009) - 1);
  x %= (1000000009);
  if (y == 0) y = (1000000009) - 1;
  long long int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % (1000000009);
    x = (x * x) % (1000000009);
    y >>= 1;
  }
  return res;
}
long long int modInverse(long long int a, long long int m = (1000000009)) {
  return expo_pow(a, m - 2);
}
long long int p2[40];
void comp() {
  p2[0] = 1;
  for (int i = (1); i < (40); i++) p2[i] = p2[i - 1] * 2;
}
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n + 2];
  int b[m + 2];
  int cnt[40];
  memset(cnt, 0, sizeof(cnt));
  for (int i = (1); i < (n + 1); i++) {
    cin >> a[i];
    long long int tmp = a[i];
    for (int j = (0); j < (40); j++) {
      long long int chk = 1ll << j;
      if (chk & tmp) {
        cnt[j]++;
      }
    }
  }
  for (int i = (1); i < (m + 1); i++) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1);
  int beg = 1, end = m;
  int ans = 0;
  while (beg <= end) {
    int mid = (beg + end) / 2;
    int tmp[40];
    for (int j = (0); j < (40); j++) {
      tmp[j] = cnt[j];
    }
    int first = 0;
    for (int i = (1); i < (mid + 1); i++) {
      int j = b[i];
      while (j < 40 && !tmp[j]) {
        j++;
      }
      if (j == 40) {
        first = 1;
        break;
      }
      long long int rem = p2[j] - p2[b[i]];
      tmp[j]--;
      for (int j = (0); j < (40); j++) {
        long long int chk = 1ll << j;
        if (chk & rem) tmp[j]++;
      }
    }
    if (!first) {
      ans = max(ans, mid);
      beg = mid + 1;
    } else
      end = mid - 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  comp();
  while (T--) {
    solve();
  }
}
