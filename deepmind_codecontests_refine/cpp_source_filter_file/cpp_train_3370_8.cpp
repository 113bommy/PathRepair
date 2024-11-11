#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int inf = 0x3F3F3F3F;
struct passenger_Tp {
  int t, fr, to, id;
  bool operator<(const passenger_Tp &p) const {
    if (t != p.t)
      return t < p.t;
    else
      return id < p.id;
  }
} p[maxn], q[maxn];
struct node_Tp {
  int pos, id;
  bool operator<(const node_Tp &n0) const {
    if (pos != n0.pos)
      return pos < n0.pos;
    else
      return id < n0.id;
  }
  bool operator>(const node_Tp &n0) const {
    if (pos != n0.pos)
      return pos > n0.pos;
    else
      return id > n0.id;
  }
  bool operator==(const node_Tp &n0) const {
    return (pos == n0.pos) && (id == n0.id);
  }
};
int n, m, pos_cur, pas_cur, out_cnt;
long long tim, ans[maxn];
set<node_Tp, less<node_Tp> > to_up, from_up;
set<node_Tp, greater<node_Tp> > to_down, from_down;
namespace solver {
void init() {
  scanf("%d%d", &n, &m);
  for (int ti, si, ei, i = 1; i <= n; i++) {
    scanf("%d%d%d", &ti, &si, &ei);
    p[i] = q[i] = (passenger_Tp){ti, si, ei, i};
  }
  sort(p + 1, p + 1 + n);
}
void add_from() {
  while (pas_cur <= n && p[pas_cur].t == tim) {
    if (p[pas_cur].fr == pos_cur) {
      if (p[pas_cur].to > pos_cur)
        to_up.insert((node_Tp){p[pas_cur].to, p[pas_cur].id});
      else
        to_down.insert((node_Tp){p[pas_cur].to, p[pas_cur].id});
    } else {
      if (p[pas_cur].to > pos_cur)
        from_up.insert((node_Tp){p[pas_cur].fr, p[pas_cur].id});
      else
        from_down.insert((node_Tp){p[pas_cur].fr, p[pas_cur].id});
    }
    ++pas_cur;
  }
}
void main() {
  node_Tp now1, now2, now;
  int siz1, siz2;
  out_cnt = 0, tim = 0, pas_cur = 1, pos_cur = 1;
  to_up.insert((node_Tp){inf, 0}), from_up.insert((node_Tp){inf, 0});
  to_down.insert((node_Tp){-inf, 0}), from_down.insert((node_Tp){-inf, 0});
  while (out_cnt != n) {
    siz1 = to_up.size() + from_up.size(),
    siz2 = to_down.size() + from_down.size();
    if (siz1 == 2 && siz2 == 2) {
      if (pas_cur <= n) tim = p[pas_cur].t, add_from();
    } else {
      if (siz1 >= siz2) {
        now1 = *(to_up.begin()), now2 = *(from_up.begin());
        if (pas_cur <= n &&
            p[pas_cur].t - tim < min(now1.pos - pos_cur, now2.pos - pos_cur)) {
          pos_cur += p[pas_cur].t - tim, tim = p[pas_cur].t, add_from();
          continue;
        }
        if (now1 > now2) swap(now1, now2);
        tim += now1.pos - pos_cur, pos_cur = now1.pos;
        while ((now = *(to_up.begin())).pos == pos_cur)
          ans[now1.id] = tim, ++out_cnt, to_up.erase(now);
        while ((now = *(from_up.begin())).pos == pos_cur) {
          from_up.erase(now);
          if (q[now.id].to > pos_cur)
            to_up.insert((node_Tp){q[now.id].to, now.id});
          else
            to_down.insert((node_Tp){q[now.id].to, now.id});
        }
        add_from();
      } else {
        now1 = *(to_down.begin()), now2 = *(from_down.begin());
        if (pas_cur <= n &&
            p[pas_cur].t - tim < min(pos_cur - now1.pos, pos_cur - now2.pos)) {
          pos_cur -= p[pas_cur].t - tim, tim = p[pas_cur].t, add_from();
          continue;
        }
        if (now1 < now2) swap(now1, now2);
        tim += pos_cur - now1.pos, pos_cur = now1.pos;
        while ((now = *(to_down.begin())).pos == pos_cur)
          ans[now1.id] = tim, ++out_cnt, to_down.erase(now);
        while ((now = *(from_down.begin())).pos == pos_cur) {
          from_down.erase(now);
          if (q[now.id].to > pos_cur)
            to_up.insert((node_Tp){q[now.id].to, now.id});
          else
            to_down.insert((node_Tp){q[now.id].to, now.id});
        }
        add_from();
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
}
}  // namespace solver
int main() {
  solver::init();
  solver::main();
  return 0;
}
