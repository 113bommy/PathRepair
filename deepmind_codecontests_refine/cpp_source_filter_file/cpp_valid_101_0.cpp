#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXM = 2e5 + 10;
const int MAXK = 3e5 + 10;
struct Pt {
  int x, y;
};
int n, m, kkk;
int xx[MAXN], yy[MAXM];
pair<int, int> p[MAXK];
Pt pt[MAXM];
inline bool cmpx(Pt qwq, Pt qaq) { return qwq.x < qaq.x; }
inline bool cmpy(Pt qwq, Pt qaq) { return qwq.y < qaq.y; }
void solve() {
  scanf("%d%d%d", &n, &m, &kkk);
  for (int i = 1; i <= n; i++) scanf("%d", &xx[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &yy[i]);
  for (int i = 1; i <= kkk; i++) scanf("%d%d", &p[i].first, &p[i].second);
  int cnt_id = 0;
  for (int i = 1; i <= kkk; i++) {
    int pos1 = lower_bound(xx + 1, xx + n + 1, p[i].first) - xx;
    int pos2 = lower_bound(yy + 1, yy + n + 1, p[i].second) - yy;
    if (xx[pos1] == p[i].first && yy[pos2] == p[i].second) continue;
    pt[++cnt_id].x = p[i].first;
    pt[cnt_id].y = p[i].second;
  }
  long long ans = 0;
  sort(pt + 1, pt + cnt_id + 1, cmpx);
  map<int, int> mmp;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    long long tot = 0;
    mmp.clear();
    while (idx + 1 <= cnt_id && pt[idx + 1].x < xx[i]) {
      idx++;
      ans += tot - mmp[pt[idx].y];
      mmp[pt[idx].y]++;
      tot++;
    }
    while (idx + 1 <= cnt_id && pt[idx + 1].x == xx[i]) idx++;
  }
  sort(pt + 1, pt + cnt_id + 1, cmpy);
  idx = 0;
  for (int i = 1; i <= m; i++) {
    long long tot = 0;
    mmp.clear();
    while (idx + 1 <= cnt_id && pt[idx + 1].y < yy[i]) {
      idx++;
      ans += tot - mmp[pt[idx].x];
      mmp[pt[idx].x]++;
      tot++;
    }
    while (idx + 1 <= cnt_id && pt[idx + 1].y == yy[i]) idx++;
  }
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
