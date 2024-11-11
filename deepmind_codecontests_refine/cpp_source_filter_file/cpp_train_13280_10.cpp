#include <bits/stdc++.h>
using namespace std;
const long long dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const long long dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
                dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const long long mod = 1000000007;
const long long base = 311;
const long long N = 1e7 + 5;
long long n, k, a[N], b[N];
long long calc(long long mid) {
  for (int i = 1; i <= 1e7; ++i) {
    b[i] = a[i];
  }
  long long ans = 0;
  for (int i = 1e7; i >= mid; --i) {
    if (i >= 2 * mid) {
      b[i / 2] += b[i];
      b[i / 2 + i % 2] += b[i];
    } else {
      ans += b[i];
    }
  }
  return ans;
}
void gogo() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  long long l = 2, r = 1e7, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (calc(mid) >= k) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  gogo();
  return 0;
}
