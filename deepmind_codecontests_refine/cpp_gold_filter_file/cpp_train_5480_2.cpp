#include <bits/stdc++.h>
using namespace std;
int n, m, incr, dmg, bounty;
struct Upd {
  int t, h;
  bool operator<(const Upd &ot) const {
    if (t == ot.t) return h < ot.h;
    return t < ot.t;
  }
};
struct Enemy {
  int m, st, reg;
} E[100002];
vector<Upd> U[100002];
int Time[100002 * 4], bonus;
map<int, int> idx;
int sum[100002 * 4];
long long ans;
int Div(int dmg, int e, int reg) {
  if (dmg >= e && reg)
    return (dmg - e) / reg;
  else
    return -1;
}
void compTime() {
  for (int i = 1; i <= n; ++i)
    if (E[i].m > dmg) {
      sort(U[i].begin(), U[i].end());
      int t = Div(dmg, E[i].st, E[i].reg);
      if (U[i].empty()) {
        if (!E[i].reg && E[i].st <= dmg) ++bonus;
        if (t > 0) Time[++Time[0]] = t;
      } else {
        if (!E[i].reg && E[i].st <= dmg) t = U[i][0].t - 1;
        if (t > 0) Time[++Time[0]] = min(t, U[i][0].t - 1);
        int sz = U[i].size();
        for (int j = 0; j < sz; ++j) {
          Time[++Time[0]] = U[i][j].t;
          if (U[i][j].h > dmg) continue;
          int t = Div(dmg, U[i][j].h, E[i].reg) + U[i][j].t;
          if (!E[i].reg) {
            if (j < sz - 1) Time[++Time[0]] = U[i][j + 1].t - 1;
            continue;
          }
          if (t > 0 && (j == sz - 1 || U[i][j + 1].t > t))
            Time[++Time[0]] = t;
          else if (t > 0)
            Time[++Time[0]] = U[i][j + 1].t - 1;
        }
      }
    }
  int len = Time[0];
  Time[0] = 0;
  Time[++len] = 0;
  sort(Time + 1, Time + len + 1);
  for (int i = 1; i <= len; ++i)
    if (!idx[Time[i]]) {
      idx[Time[i]] = ++Time[0];
      Time[Time[0]] = Time[i];
    }
  for (int i = 1; i <= n; ++i)
    if (E[i].m > dmg) {
      int t = Div(dmg, E[i].st, E[i].reg);
      if (U[i].empty()) {
        if (t >= 0) {
          ++sum[0];
          --sum[idx[t] + 1];
        }
      } else {
        if (!E[i].reg && E[i].st <= dmg) t = U[i][0].t - 1;
        if (t >= 0) {
          ++sum[0];
          --sum[idx[min(t, U[i][0].t - 1)] + 1];
        }
        int sz = U[i].size();
        for (int j = 0; j < sz; ++j) {
          if (U[i][j].h > dmg) continue;
          ++sum[idx[U[i][j].t]];
          int t = Div(dmg, U[i][j].h, E[i].reg) + U[i][j].t;
          if (!E[i].reg) {
            if (j < sz - 1) --sum[idx[U[i][j + 1].t - 1] + 1];
            continue;
          }
          if (t >= 0 && (j == sz - 1 || U[i][j + 1].t > t))
            --sum[idx[t] + 1];
          else if (t >= 0)
            --sum[idx[U[i][j + 1].t - 1] + 1];
        }
      }
    }
}
void cntKill() {
  for (int i = 1; i <= Time[0]; ++i) {
    sum[i] += sum[i - 1];
    long long gold = 1LL * (1LL * incr * Time[i] + bounty) * (bonus + sum[i]);
    ans = max(ans, gold);
  }
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &bounty, &incr, &dmg);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &E[i].m, &E[i].st, &E[i].reg);
    if (E[i].m <= dmg || (incr && E[i].st <= dmg && !E[i].reg)) ++bonus;
  }
  if (bonus && incr) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    int ti, ei, hi;
    scanf("%d%d%d", &ti, &ei, &hi);
    U[ei].push_back(Upd{ti, hi});
  }
  compTime();
  cntKill();
  printf("%lld\n", ans);
  return 0;
}
