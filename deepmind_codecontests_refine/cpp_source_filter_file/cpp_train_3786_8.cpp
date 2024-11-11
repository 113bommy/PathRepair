#include <bits/stdc++.h>
using namespace std;
struct mirror {
  int isTop, l, r, score;
} mrr[111];
int h1, h2, n, isMrr[2][10001111], cnt[111];
int check(int t, int up) {
  double dx, xnow;
  memset(cnt, 0, sizeof(cnt));
  if (t == 1) {
    if (up) {
      xnow = 100000.0 * (100 - h1) / (100 - h1 + 100 - h2);
    } else {
      xnow = 100000.0 * h1 / (h1 + h2);
    }
  } else {
    int l1, l2;
    if (up % 2 == 1)
      l1 = 100 - h1;
    else
      l2 = h1;
    if ((up + t) % 2 == 0)
      l2 = 100 - h2;
    else
      l2 = h2;
    dx = 100000.0 / ((t - 1) + (l1 + l2) / 100.0);
    xnow = l1 * dx / 100.0;
  }
  for (int i = 0; i < t; i++, xnow += dx) {
    bool found = 0;
    for (int j = 0; j < n; j++) {
      if ((i + up) % 2 == mrr[j].isTop)
        if (mrr[j].l <= xnow && xnow <= mrr[j].r) {
          cnt[j]++;
          found = 1;
        }
    }
    if (!found) return 0;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (1 < cnt[i])
      return 0;
    else if (0 < cnt[i])
      res += mrr[i].score;
  }
  return res;
}
void input() {
  memset(isMrr, -1, sizeof(isMrr));
  cin >> h1 >> h2 >> n;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> mrr[i].score >> ch >> mrr[i].l >> mrr[i].r;
    for (int j = mrr[i].l; j < mrr[i].r; j++) {
      isMrr[ch == 'T'][j] = i;
    }
    mrr[i].isTop = (ch == 'T');
  }
}
void solve() {
  int res = 0;
  for (int t = 1; t <= n; t++) {
    res = max(res, check(t, 1));
    res = max(res, check(t, 0));
  }
  cout << res << endl;
}
int main() {
  input();
  solve();
}
