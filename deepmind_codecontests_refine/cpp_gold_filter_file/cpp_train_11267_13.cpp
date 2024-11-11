#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18;
const long long inf = 1e18;
const double eps = 1e-8;
const double pi = acos(-1);
int p;
struct people {
  int aud;
  int player[15];
  void read1() { scanf("%d", &aud); }
  void read2() {
    int i;
    for (i = 0; i < p; i++) {
      scanf("%d", &player[i]);
    }
  }
  friend bool operator<(const people &a, const people &b) {
    return a.aud > b.aud;
  }
};
people a[100005];
long long dp[1 << 7];
long long newdp[1 << 7];
int cnt[1 << 7];
int main() {
  int n, k;
  scanf("%d%d%d", &n, &p, &k);
  int i;
  for (i = 0; i < 128; i++) {
    int j;
    for (j = 0; j < 7; j++) {
      if ((1 << j) & i) {
        cnt[i]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    a[i].read1();
  }
  for (i = 0; i < n; i++) {
    a[i].read2();
  }
  sort(a, a + n);
  for (i = 0; i < k; i++) {
    dp[0] += a[i].aud;
  }
  for (i = 0; i < n; i++) {
    int j;
    for (j = 0; j < (1 << p); j++) {
      newdp[j] = max(newdp[j], dp[j]);
      int l;
      for (l = 0; l < p; l++) {
        if ((1 << l) & j) {
          continue;
        }
        if (i >= k + cnt[j]) {
          newdp[j ^ (1 << l)] =
              max(newdp[j ^ (1 << l)], dp[j] + a[i].player[l]);
        } else {
          newdp[j ^ (1 << l)] =
              max(newdp[j ^ (1 << l)],
                  dp[j] + a[i].player[l] - a[i].aud + a[k + cnt[j]].aud);
        }
      }
    }
    for (j = 0; j < (1 << p); j++) {
      dp[j] = newdp[j];
      newdp[j] = 0;
    }
  }
  printf("%lld\n", dp[(1 << p) - 1]);
  return 0;
}
