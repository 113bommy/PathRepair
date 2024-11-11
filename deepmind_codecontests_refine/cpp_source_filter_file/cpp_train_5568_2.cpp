#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int w[MAXN], h[MAXN];
bool chan[MAXN];
int chang[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &w[i], &h[i]);
  }
  int ans = 1 << 30;
  for (int i = 1; i <= n; ++i) {
    memset(chan, 0, sizeof(chan));
    int maxh = h[i];
    bool rtb = 0;
    int cnt = 0;
    int tot_w = w[i];
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (h[j] > maxh) {
        if (w[j] > maxh) {
          rtb = 1;
          break;
        }
        chan[j] = 1;
        ++cnt;
        tot_w += h[j];
      } else {
        tot_w += w[j];
      }
    }
    tot_w *= maxh;
    if (rtb || cnt > n / 2) {
      continue;
    }
    int changcnt = 0;
    cnt = (n - cnt * 2) / 2;
    for (int j = 1; j <= n; ++j) {
      if (chan[j] || i == j || w[j] > h[i]) continue;
      int nowsolve = w[j] * h[i] - h[j] * h[i];
      if (nowsolve > 0) chang[++changcnt] = nowsolve;
    }
    sort(chang + 1, chang + 1 + changcnt);
    for (int j = 1; j <= cnt && changcnt; ++j) {
      tot_w -= chang[changcnt--];
    }
    ans = min(ans, tot_w);
  }
  for (int i = 1; i <= n; ++i) {
    memset(chan, 0, sizeof(chan));
    int maxh = w[i];
    bool rtb = 0;
    int cnt = 0;
    int tot_w = h[i];
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (h[j] > maxh) {
        if (w[j] > maxh) {
          rtb = 1;
          break;
        }
        chan[j] = 1;
        ++cnt;
        tot_w += h[j];
      } else {
        tot_w += w[j];
      }
    }
    tot_w *= maxh;
    if (rtb || cnt > n / 2) {
      continue;
    }
    int changcnt = 0;
    cnt = (n - cnt * 2) / 2 - 1;
    for (int j = 1; j <= n; ++j) {
      if (chan[j] || i == j || w[j] > maxh) continue;
      int nowsolve = w[j] * maxh - h[j] * maxh;
      if (nowsolve > 0) chang[++changcnt] = nowsolve;
    }
    sort(chang + 1, chang + 1 + changcnt);
    for (int j = 1; j <= cnt && changcnt > 0; ++j) {
      tot_w -= chang[changcnt--];
    }
    ans = min(ans, tot_w);
  }
  printf("%d", ans);
  return 0;
}
