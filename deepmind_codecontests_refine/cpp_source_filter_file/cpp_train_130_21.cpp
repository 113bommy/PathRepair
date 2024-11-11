#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxa = N;
int a[N], n, f[N], sq;
int cnt[maxa], ccnt[N];
void Max(int &x, int y) {
  if (x < y) x = y;
}
int solve(int maxans) {
  int mx = 0;
  for (int i = 1; i <= maxans; i++) {
    if (cnt[i] > cnt[mx]) mx = i;
  }
  int ans = 0;
  for (int i = 1; i <= maxans; i++) {
    if (i == mx || !cnt[i]) continue;
    if (cnt[i] <= sq) continue;
    for (int j = 1; j <= n; j++) {
      if (a[j] == mx) {
        f[j] = 1;
      } else if (a[j] == i) {
        f[j] = -1;
      } else {
        f[j] = 0;
      }
    }
    unordered_map<int, int> mp;
    mp[0] = 0;
    int now = 0;
    for (int j = 1; j <= n; j++) {
      now += f[j];
      if (!mp.count(now))
        mp[now] = j;
      else {
        Max(ans, j - mp[now]);
      }
    }
  }
  return ans;
}
int solve2(int maxti) {
  int ans = 0;
  for (int i = 1; i <= maxti; i++) {
    memset(cnt, 0, sizeof cnt);
    memset(ccnt, 0, sizeof ccnt);
    for (int r = 1, l = 1; r <= n; r++) {
      ccnt[cnt[a[r]]]--;
      cnt[a[r]]++;
      ccnt[cnt[a[r]]]++;
      while (cnt[a[r]] > i && l <= r) {
        ccnt[cnt[a[l]]]--;
        cnt[a[l]]--;
        ccnt[cnt[a[l]]]++;
        l++;
      }
      if (ccnt[i] >= 2) Max(ans, r - l + 1);
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  sq = 448;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) continue;
    ccnt[cnt[i]]++;
    if (mx < cnt[i]) mx = cnt[i];
  }
  if (ccnt[mx] >= 2) {
    printf("%d\n", n);
  } else {
    printf("%d\n", max(solve(n), solve(sq)));
  }
}
