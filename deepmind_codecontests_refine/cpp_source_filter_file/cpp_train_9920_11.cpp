#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, mx, big, a[N], cnt[N], lst[N << 1], processed[N];
int solve1(int num) {
  memset(lst, -1, sizeof lst);
  int res = 0;
  int now = 0;
  lst[now + n] = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == big) ++now;
    if (a[i] == num) --num;
    if (lst[now + n] != -1) {
      res = max(res, i - lst[now + n]);
    }
    if (lst[n + now] == -1) {
      lst[n + now] = i;
    }
  }
  return res;
}
int solve2(int limit) {
  int res = 0;
  int eql = 0;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1, j = 1; i <= n; ++i) {
    ++cnt[a[i]];
    if (cnt[a[i]] == limit) ++eql;
    while (j <= i && cnt[a[i]] > limit) {
      --cnt[a[j]];
      if (cnt[a[j]] == limit - 1) --eql;
      ++j;
    }
    if (eql >= 2) {
      res = max(res, i - j + 1);
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ++cnt[a[i]];
    if (cnt[a[i]] > mx) {
      mx = cnt[a[i]];
      big = a[i];
    }
  }
  int ans = 0;
  int up = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    if (cnt[a[i]] >= up && a[i] != big && !processed[a[i]]) {
      processed[a[i]] = 1;
      ans = max(ans, solve1(a[i]));
    }
  }
  for (int i = 1; i <= up; ++i) ans = max(ans, solve2(i));
  cout << ans;
  return 0;
}
