#include <bits/stdc++.h>
using namespace std;
struct info {
  int tm;
  int enemy;
  int hth;
};
bool cmp(const info &a, const info &b) { return a.tm < b.tm; }
vector<info> v;
set<int> upd[100003];
map<int, int> cnt;
int mxh[100003], rh[100003], vis[100003];
int main() {
  int n, m, bnty, incr, dmg;
  scanf("%d%d", &(n), &(m));
  scanf("%d%d", &(bnty), &(incr));
  scanf("%d", &(dmg));
  int inf = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    int mh, sh, r;
    scanf("%d%d", &(mh), &(sh));
    scanf("%d", &(r));
    mxh[i + 1] = mh;
    rh[i + 1] = r;
    v.push_back({0, i + 1, sh});
    if (r > 0 && mh <= dmg && incr) {
      inf = 1;
    }
  }
  for (int(i) = (0); (i) < (m); (i)++) {
    int t, enmy, updh;
    scanf("%d%d", &(t), &(enmy));
    scanf("%d", &(updh));
    v.push_back({t, enmy, updh});
    upd[enmy].insert(t);
  }
  if (inf) {
    printf("-1\n");
    return 0;
  }
  sort(v.begin(), v.end(), cmp);
  int lt = n + m;
  for (int(i) = (0); (i) < (lt); (i)++) {
    info &x = v[i];
    if (x.hth > dmg) {
      if (vis[x.enemy]) {
        vis[x.enemy] = 0;
        cnt[x.tm]--;
        cnt[x.tm - 1] += 0;
      }
    } else {
      if (!vis[x.enemy]) {
        cnt[x.tm]++;
        vis[x.enemy] = 1;
      }
      if (vis[x.enemy]) {
        if (rh[x.enemy] > 0) {
          int inv_tm = x.tm + (dmg - x.hth) / rh[x.enemy] + 1;
          if (upd[x.enemy].upper_bound(x.tm) ==
              upd[x.enemy].upper_bound(inv_tm)) {
            cnt[inv_tm]--;
            vis[x.enemy] = 0;
            cnt[inv_tm - 1] += 0;
          }
        }
        if (rh[x.enemy] == 0 && incr > 0 &&
            upd[x.enemy].upper_bound(x.tm) == upd[x.enemy].end()) {
          printf("-1\n");
          return 0;
        }
      }
    }
  }
  long long ans = 0;
  int val = 0;
  for (auto &t : cnt) {
    val += t.second;
    ans = max(ans, 1ll * val * (1ll * t.first * incr + 1ll * bnty));
  }
  printf("%I64d\n", ans);
  return 0;
}
