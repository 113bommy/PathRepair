#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn], cnt[maxn];
int n, offset;
bool test(int x) {
  for (int i = x + 1; i <= n / 2; i++) {
    if (a[i] != a[n - i + 1]) {
      return false;
    }
  }
  static int ms[maxn];
  fill(ms + 1, ms + n + 1, 0);
  for (int i = offset; i <= x; i++) {
    ms[a[i]]++;
  }
  for (int i = max(n - x + 1, x + 1); i <= n - offset + 1; i++) {
    if (--ms[a[i]] < 0) {
      return false;
    }
  }
  for (int i = 1, odd_n = 0; i <= n; i++) {
    if (ms[i] & 1) {
      if (++odd_n > 1) {
        return false;
      }
    }
  }
  return true;
}
long long solve() {
  int L = offset, R = n;
  while (L < R) {
    int M = (L + R) >> 1;
    if (test(M)) {
      R = M;
    } else {
      L = M + 1;
    }
  }
  return (long long)offset * (n - R + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  offset = 1;
  while (offset <= n / 2 && a[offset] == a[n - offset + 1]) {
    offset++;
  }
  if (offset > n / 2) {
    return cout << (long long)n * (n + 1) / 2 << endl, 0;
  }
  for (int i = 1, odd_n = 0; i <= n; i++) {
    if (cnt[i] & 1) {
      if (++odd_n > 1) {
        return cout << 0 << endl, 0;
      }
    }
  }
  long long ans = solve();
  reverse(a + 1, a + n + 1);
  ans += solve();
  ans -= (long long)offset * offset;
  cout << ans << endl;
  return 0;
}
