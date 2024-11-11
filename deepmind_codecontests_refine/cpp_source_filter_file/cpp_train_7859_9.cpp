#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXK = 1005;
const int MAXQ = 35005;
const int P = 1e7 + 19;
const int Q = 1e9 + 7;
int n, k, q, exhibit_cnt, ask_cnt;
struct event {
  int type, x;
} evt[MAXQ];
int powp[MAXK];
int v[MAXQ], w[MAXQ];
int display_start[MAXQ], display_end[MAXQ];
vector<int> t[4 * MAXQ];
void update(int x, int l, int r, int ll, int rr, int v) {
  if (r < ll || l > rr || l > r) {
    return;
  }
  if (ll <= l && r <= rr) {
    return t[x].push_back(v);
  }
  int mid = l + r >> 1;
  update(2 * x, l, mid, ll, rr, v);
  update(2 * x + 1, mid + 1, r, ll, rr, v);
}
int dp[MAXN][MAXK];
int res[MAXQ];
void go(int x, int l, int r, int last) {
  for (int exhibit = last + 1; exhibit < last + 1 + (int)t[x].size();
       exhibit++) {
    for (int j = 0; j < MAXK; j++) {
      dp[exhibit][j] = 0;
    }
  }
  for (int exhibit = last + 1; exhibit < last + 1 + (int)t[x].size();
       exhibit++) {
    for (int mass = 1; mass <= k; mass++) {
      if (exhibit) dp[exhibit][mass] = dp[exhibit - 1][mass];
      if (mass >= w[t[x][exhibit - last - 1]]) {
        if (exhibit) {
          dp[exhibit][mass] =
              max(dp[exhibit][mass],
                  dp[exhibit - 1][mass - w[t[x][exhibit - last - 1]]] +
                      v[t[x][exhibit - last - 1]]);
        } else
          dp[exhibit][mass] =
              max(dp[exhibit][mass], v[t[x][exhibit - last - 1]]);
      }
    }
  }
  if (l == r) {
    for (int mass = 1; mass <= k; mass++) {
      res[l] += (1ll * dp[last + (int)t[x].size()][mass] * powp[mass - 1]) % Q;
      res[l] %= Q;
    }
    return;
  }
  int mid = l + r >> 1;
  go(2 * x, l, mid, last + (int)t[x].size());
  go(2 * x + 1, mid + 1, r, last + (int)t[x].size());
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < MAXQ; i++) {
    display_end[i] = 0x3f3f3f3f;
  }
  powp[0] = 1;
  for (int i = 1; i < MAXK; i++) {
    powp[i] = (1ll * powp[i - 1] * P) % Q;
  }
  for (int i = 1; i <= n; i++) {
    evt[i].type = 1;
    evt[i].x = ++exhibit_cnt;
    scanf("%d %d", v + evt[i].x, w + evt[i].x);
    display_start[i] = ask_cnt;
  }
  scanf("%d", &q);
  for (int i = n + 1; i <= n + q; i++) {
    scanf("%d", &evt[i].type);
    if (evt[i].type == 1) {
      evt[i].x = ++exhibit_cnt;
      scanf("%d %d", v + evt[i].x, w + evt[i].x);
      display_start[evt[i].x] = ask_cnt + 1;
    } else if (evt[i].type == 2) {
      scanf("%d", &evt[i].x);
      display_end[evt[i].x] = ask_cnt;
    } else {
      ask_cnt++;
    }
  }
  for (int i = 1; i <= exhibit_cnt; i++) {
    if (display_end[i] == 0) continue;
    if (display_start[i] == 0) display_start[i] = 1;
    if (display_start[i] > ask_cnt) continue;
    if (display_end[i] == 0x3f3f3f3f) display_end[i] = ask_cnt;
    update(1, 1, ask_cnt, display_start[i], display_end[i], i);
  }
  go(1, 1, ask_cnt, -1);
  for (int i = 1; i <= ask_cnt; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}
