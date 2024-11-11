#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = (int)3e5 + 17;
const int mod = (int)1e9 + 7;
int N, M, S, T, K;
int a[MAX_N], w[MAX_N];
struct Fenwick_0 {
  long long bt[MAX_N];
  void init() {
    for (int i = 0; i <= N; i++) bt[i] = 0;
  }
  void add(int idx, int w) {
    for (; idx <= N; idx += idx & -idx) bt[idx] += w;
  }
  long long sum(int idx) {
    long long ans = 0;
    for (; idx > 0; idx -= idx & -idx) ans += bt[idx];
    return ans;
  }
} W;
struct Fenwick_1 {
  int bt[MAX_N];
  void init() {
    for (int i = 0; i <= N; i++) bt[i] = 0;
  }
  void add(int idx, int w) {
    for (; idx <= N; idx += idx & -idx) (bt[idx] += w) %= mod;
  }
  int sum(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & -idx) (ans += bt[idx]) %= mod;
    return ans;
  }
} F;
int main() {
  while (~scanf("%d %d", &N, &M)) {
    W.init();
    F.init();
    for (int i = 1; i <= N; i++) {
      scanf("%d", &a[i]);
      a[i] -= i;
    }
    for (int i = 1; i <= N; i++) {
      scanf("%d", &w[i]);
      W.add(i, w[i]);
      F.add(i, 1LL * a[i] * w[i] % mod);
    }
    while (M--) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (x < 0) {
        x *= -1;
        W.add(x, y - w[x]);
        F.add(x, 1LL * (y - w[x]) * a[x] % mod);
        w[x] = y;
      } else {
        long long sl = W.sum(x - 1), sr = W.sum(y);
        sr = (sr - sl + 1) / 2;
        int l = x, r = y;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (W.sum(mid) - sl >= sr)
            r = mid - 1;
          else
            l = mid + 1;
        }
        long long ans = (F.sum(y) - F.sum(l)) -
                        (W.sum(y) - W.sum(l)) % mod * 1LL * a[l] % mod -
                        ((F.sum(l) - F.sum(x - 1)) -
                         (W.sum(l) - W.sum(x - 1)) % mod * 1LL * a[l] % mod);
        printf("%lld\n", (ans + mod) % mod);
      }
    }
  }
  return 0;
}
