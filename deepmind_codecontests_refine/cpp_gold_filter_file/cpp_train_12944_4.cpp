#include <bits/stdc++.h>
using namespace std;
struct node {
  char s[505];
  int len;
} t[2005];
int hgt[2005], cnt = 0, n, k;
int dp[4005][2005];
inline bool cmp(node a, node b) {
  for (int i = 1; i <= a.len && i <= b.len; i++) {
    if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
  }
  return a.len < b.len;
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
int cal(int l, int r) {
  int id = ++cnt, i, j;
  if (l == r) return id;
  int minn = 666, pos = -1;
  for (i = l; i < r; i++) {
    if (hgt[i] < minn) {
      minn = hgt[i];
      pos = i;
    }
  }
  int lc = cal(l, pos), rc = cal(pos + 1, r);
  for (i = 1; i <= k && i <= r - l + 1; i++) {
    for (j = max(0, i - min(k, r - pos)); j <= min(i, pos - l + 1); j++) {
      dp[id][i] =
          max(dp[id][i], dp[lc][j] + dp[rc][i - j] + minn * j * (i - j));
    }
  }
  return id;
}
int main() {
  int i, j, l;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%s", t[i].s + 1);
    t[i].len = strlen(t[i].s + 1);
  }
  sort(t + 1, t + n + 1, cmp);
  for (i = 1; i < n; i++) {
    hgt[i] = min(t[i].len, t[i + 1].len);
    for (j = 1; j <= t[i].len && j <= t[i + 1].len; j++) {
      if (t[i].s[j] != t[i + 1].s[j]) {
        hgt[i] = j - 1;
        break;
      }
    }
  }
  int o = cal(1, n);
  printf("%d\n", dp[o][k]);
  return 0;
}
