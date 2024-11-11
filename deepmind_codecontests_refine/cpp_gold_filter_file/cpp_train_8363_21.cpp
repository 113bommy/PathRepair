#include <bits/stdc++.h>
using namespace std;
const int maxv = 5 + 2;
const int INF = 0x3f3f3f3f;
int n, s, ans1, ans2, ans3, mn = INF;
int cnt[maxv];
int f(int k3, int k4, int k5) {
  return abs(cnt[3] * k3 - cnt[4] * k4) + abs(cnt[4] * k4 - cnt[5] * k5);
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = s / n; ~i; i--)
    for (int j = (s - cnt[3] * i) / (n - cnt[3]); j >= i; j--) {
      int k = (s - cnt[3] * i - cnt[4] * j) / cnt[5];
      if (k * cnt[5] - j * cnt[4] >= mn) break;
      if (i * cnt[3] + j * cnt[4] + k * cnt[5] == s && mn > f(i, j, k)) {
        mn = f(i, j, k);
        ans1 = i, ans2 = j, ans3 = k;
      }
    }
  if (mn != INF)
    printf("%d %d %d", ans1, ans2, ans3);
  else
    printf("-1");
  return 0;
}
