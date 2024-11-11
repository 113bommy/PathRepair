#include <bits/stdc++.h>
using namespace std;
const long long LINF = 0x3FFFFFFFFFFFFFFF;
struct F {
  int x, k, pset;
} friends[101];
bool cmp(F a, F b) { return a.k < b.k; }
long long dp[1 << 21];
int main() {
  int n, m, b;
  scanf("%d %d %d", &n, &m, &b);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d %d %d", &friends[i].x, &friends[i].k, &t);
    for (int j = 0; j < t; j++) {
      int p;
      scanf("%d", &p);
      friends[i].pset |= 1 << (p - 1);
    }
  }
  sort(friends, friends + n, cmp);
  long long ans = LINF;
  for (int i = 0; i < 1 << 21; i++) dp[i] = LINF;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << m; j++) {
      dp[j | friends[i].pset] =
          min(dp[j | friends[i].pset], dp[j] + friends[i].x);
    }
    ans = min(ans, dp[(1 << m) - 1] + friends[i].k * (long long)b);
  }
  if (ans == LINF)
    printf("-1\n");
  else
    cout << ans << endl;
  return 0;
}
