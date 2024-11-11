#include <bits/stdc++.h>
using namespace std;
int n, m;
long long b;
long long dp[2][1 << 20];
struct F {
  int p;
  long long x, k;
} f[100];
bool cmp(F a, F b) { return a.k < b.k; }
int main() {
  while (cin >> n >> m >> b) {
    for (int i = (0); i < (n); i++) {
      int mi;
      cin >> f[i].x >> f[i].k >> mi;
      f[i].p = 0;
      while (mi--) {
        int t;
        cin >> t;
        t--;
        f[i].p |= 1 << t;
      }
    }
    sort(f, f + n, cmp);
    long long ans = 1LL << 60;
    dp[0][0] = 0;
    for (int bm = (1); bm < (1 << m); bm++) dp[0][bm] = 1LL << 60;
    dp[0][f[0].p] = f[0].x;
    if (f[0].p == (1 << m) - 1) ans = f[0].x + b * f[0].k;
    for (int i = (1); i < (n); i++) {
      memcpy(dp[i % 2], dp[(i + 1) % 2], sizeof(long long) * (1 << m));
      for (int bm = (0); bm < (1 << m); bm++) {
        int nbm = bm | f[i].p;
        dp[i % 2][nbm] = min(dp[i % 2][nbm], dp[(i + 1) % 2][bm] + f[i].x);
      }
      if (dp[i % 2][(1 << m) - 1] + b * f[i].k < ans)
        ans = dp[i % 2][(1 << m) - 1] + b * f[i].k;
    }
    if (ans == 1LL << 60)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
