#include <bits/stdc++.h>
using namespace std;
int a[11], dp[11][11], Cnt[11], ans, pos;
inline void Add(int &x, int y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
}
int dfs(int p, bool sta, int cnt) {
  if (p == -1) return !cnt;
  if (!sta && ~dp[p][cnt]) return dp[p][cnt];
  int res = 0;
  int up = sta ? a[p] : 9;
  for (int i = (0), i_ = (up); i <= i_; i++) {
    if (i == 4 || i == 7)
      Add(res, dfs(p - 1, sta && i == a[p], cnt - 1));
    else
      Add(res, dfs(p - 1, sta && i == a[p], cnt));
  }
  if (!sta) dp[p][cnt] = res;
  return res;
}
void Dfs(int x, int mx, int cnt, int now) {
  if (cnt >= mx) return;
  if (x == 7) {
    Add(ans, now);
    return;
  }
  for (int i = (0), i_ = (pos); i <= i_; i++)
    if (Cnt[i]) {
      Cnt[i]--;
      Dfs(x + 1, mx, cnt + i, 1LL * now * (Cnt[i] + 1) % 1000000007);
      Cnt[i]++;
    }
}
void Deal(int x) {
  while (x) {
    a[pos++] = x % 10;
    x /= 10;
  }
  for (int i = (0), i_ = (pos); i <= i_; i++) Cnt[i] = dfs(pos - 1, 1, i);
  Cnt[0]--;
  for (int i = (1), i_ = (pos); i <= i_; i++)
    if (Cnt[i]) Dfs(1, i, 0, Cnt[i]);
  printf("%d\n", ans);
}
int main() {
  int m;
  scanf("%d", &m);
  memset(dp, -1, sizeof dp);
  Deal(m);
  return 0;
}
