#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
long long x[maxn], k[maxn], s[maxn], dp[2000000], ans = 1e17, INF = 1e17,
                                                  b[maxn], p, f;
bool cmp(int g, int h) { return (k[g] < k[h]); }
int main() {
  int n, m, a;
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> k[i] >> a;
    for (int j = 0; j < a; j++) {
      cin >> f;
      s[i] |= (1 << (f - 1));
    }
  }
  for (int i = 0; i < n; i++) b[i] = i;
  sort(b, b + n, cmp);
  for (int mask = 1; mask < (1 << m); mask++) dp[mask] = INF;
  for (int i = 0; i < n; i++) {
    for (int mask = (1 << m) - 1; mask >= 0; mask--)
      dp[mask] = min(dp[mask], dp[mask & (~s[b[i]])] + x[b[i]]);
    ans = min(ans, dp[(1 << m) - 1] + (k[b[i]]) * p);
  }
  cout << ((ans == INF) ? -1 : ans) << endl;
  return 0;
}
