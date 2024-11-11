#include <bits/stdc++.h>
using namespace std;
int n, cnt[10001000];
long long tot, a, b, ans = 0;
bitset<10001000> np;
void doit(long long x, long long y) {
  if (y == 0) return;
  long long l = 1, r = x * y, mid, turn, t, z;
  while (l <= r) {
    mid = (l + r) >> 1;
    z = mid;
    t = 0;
    for (; z > 0;) {
      t += z / x;
      z /= x;
    }
    if (t >= y) {
      r = (turn = mid) - 1;
    } else {
      l = mid + 1;
    }
  }
  ans = max(ans, turn);
}
int main() {
  int x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 2; i <= 10000000; i++) {
    cnt[i] += cnt[i - 1];
  }
  np.reset();
  np[1] = 1;
  for (int i = 2; i <= 10000000; i++) {
    if (!np[i]) {
      for (int j = i + i; j <= 10000000; j += i) {
        np[j] = 1;
      }
    }
  }
  for (int i = 2; i <= 10000000; i++) {
    if (np[i]) continue;
    tot = 0;
    for (a = i; a <= 10000000; a *= i) {
      b = 0;
      for (int j = a; j <= 10000000; j += a) {
        b++;
        tot += b * (cnt[min(j + a - 1, (long long)10000000)] - cnt[j - 1]);
      }
    }
    doit(i, tot);
  }
  cout << ans;
}
