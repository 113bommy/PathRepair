#include <bits/stdc++.h>
using namespace std;
int x, y, p, r, n;
struct gripper {
  int dis, m, p, r;
  long long disori;
  bool del = false;
} gp[250020];
int lshcnt, lshm[500050], lshmcnt;
long long lsh[500050];
priority_queue<pair<int, int> > c[500050];
queue<int> availgp;
inline int lowbit(int x) { return x & -x; }
inline void insert(int p, int x) {
  for (; p <= lshcnt; p += lowbit(p)) {
    c[p].push(make_pair(-gp[x].m, x));
  }
}
inline int query(int r, int m) {
  int res = 0;
  for (; r; r -= lowbit(r)) {
    while (c[r].size() && c[r].top().first >= -m) {
      int x = c[r].top().second;
      if (!gp[x].del) {
        gp[x].del = true;
        availgp.push(x);
        ++res;
      }
      c[r].pop();
    }
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> x >> y >> p >> r >> n;
  lsh[1] = r;
  lshm[1] = p;
  for (int i = 1, xi, yi; i <= n; ++i) {
    cin >> xi >> yi >> gp[i].m >> gp[i].p >> gp[i].r;
    gp[i].disori =
        ceil(sqrt(pow((double)(xi - x), 2) + pow((double)(yi - y), 2)));
    lsh[i * 2] = gp[i].disori;
    lsh[i * 2 + 1] = gp[i].r;
    lshm[i * 2] = gp[i].p;
    lshm[i * 2 + 1] = gp[i].m;
  }
  sort(lsh + 1, lsh + 1 + n * 2 + 1);
  sort(lshm + 1, lshm + 1 + 2 * n + 1);
  lshcnt = unique(lsh + 1, lsh + 1 + 2 * n + 1) - lsh - 1;
  lshmcnt = unique(lshm + 1, lshm + 1 + 2 * n + 1) - lshm - 1;
  for (int i = 1; i <= n; ++i) {
    gp[i].dis = lower_bound(lsh + 1, lsh + 1 + lshcnt, gp[i].disori) - lsh;
    gp[i].r = lower_bound(lsh + 1, lsh + 1 + lshcnt, gp[i].r) - lsh;
    gp[i].m = lower_bound(lshm + 1, lshm + 1 + lshmcnt, gp[i].m) - lshm;
    gp[i].p = lower_bound(lshm + 1, lshm + 1 + lshmcnt, gp[i].p) - lshm;
    insert(gp[i].dis, i);
  }
  r = lower_bound(lsh + 1, lsh + 1 + lshcnt, r) - lsh;
  p = lower_bound(lshm + 1, lshm + 1 + lshmcnt, p) - lshm;
  int ans = query(r, p);
  while (!availgp.empty()) {
    int f = availgp.front();
    availgp.pop();
    ans += query(gp[f].r, gp[f].p);
  }
  cout << ans << endl;
}
