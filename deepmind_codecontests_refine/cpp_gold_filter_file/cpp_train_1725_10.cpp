#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
int cnt[(int)(2e5 + 5)], pref[(int)(2e5 + 5)];
void solve() {
  int n, mx = 0, ans = 0, s;
  scanf("%d", &n);
  scanf("%d", &s);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (i == s) {
      if (x != 0) {
        ans++;
      }
    } else
      cnt[x]++;
    mx = max(mx, x);
  }
  if (n == 1) {
    if (mx == 0) {
      printf("%d", 0);
    } else {
      printf("%d", 1);
    }
    return;
  }
  pref[0] = cnt[0];
  for (int i = 1; i <= n - 1; i++) {
    pref[i] = pref[i - 1] + cnt[i];
  }
  int finans = n, todo = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (!cnt[i]) {
      todo++;
    }
    int lef = n - 1 - (pref[i] - pref[0]);
    finans = min(finans, ans + max(lef, todo));
  }
  printf("%d", finans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
