#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int KOR = 35005;
int n, m;
int bad[N];
int P[N];
int prime[KOR];
int prost[KOR];
int cnt;
int dp[N];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline void load() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &P[i]);
  for (int i = 0; i < m; i++) scanf("%d", &bad[i]);
}
inline void erat() {
  for (int i = 2; i * i < KOR; i++) {
    if (!prime[i]) {
      prost[cnt++] = i;
      for (int j = i * i; j < KOR; j += i) prime[j] = 1;
    }
  }
}
inline int calc(int x) {
  int sol = 0;
  for (int i = 0; i < m; i++) {
    while (x % bad[i] == 0) x /= bad[i], sol--;
  }
  for (int i = 0; i < cnt && x > 1; i++) {
    while (x % prost[i] == 0) {
      x /= prost[i];
      sol++;
    }
  }
  if (x != 1) sol++;
  return sol;
}
inline void solve() {
  erat();
  int ans = 0;
  int G = 0;
  for (int i = 0; i < n; i++) {
    G = gcd(G, P[i]);
    int f = -calc(G);
    dp[i] = f * (i + 1);
    for (int j = i - 1; j >= 0; j--) dp[i] = max(dp[i], dp[j] + f * (i - j));
    ans = max(ans, dp[i]);
  }
  for (int i = 0; i < n; i++) ans += calc(P[i]);
  printf("%d\n", ans);
}
int main(void) {
  load();
  solve();
  return 0;
}
