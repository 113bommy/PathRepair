#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long nm = 0;
  bool fh = true;
  char cw = getchar();
  for (; !isdigit(cw); cw = getchar()) fh ^= (cw == '-');
  for (; isdigit(cw); cw = getchar()) nm = nm * 10 + (cw - '0');
  return fh ? nm : -nm;
}
multiset<int> S;
set<pair<int, int> > seg;
int n, t[1000020], p[1000020], m, ans[1000020], f[1000020], kd[1000020], res,
    now;
inline int fd(int x) { return f[x] == x ? x : f[x] = fd(f[x]); }
vector<int> pos[1000020];
inline void del(set<pair<int, int> >::iterator it) {
  set<pair<int, int> >::iterator l = it, r = it;
  l--, r++;
  S.erase(S.find((*it).first - (*l).second - 1));
  S.erase(S.find((*r).first - (*it).second - 1));
  S.insert((*r).first - (*l).second - 1);
  seg.erase(it);
}
inline void ins(int first, int second) {
  seg.insert(make_pair(first, second));
  set<pair<int, int> >::iterator it = seg.find(make_pair(first, second)),
                                 l = it, r = it;
  l--, r++;
  S.insert(first - (*l).second - 1), S.insert((*r).first - (*it).second - 1),
      S.erase(S.find((*r).first - (*l).second - 1));
  if (!kd[first]) return;
  int dnl = first, dnr = second;
  dnl = (kd[(*l).first] != 0) ? ((*l).second + 1)
                              : (((*l).second + first + 1) >> 1);
  dnr = (kd[(*r).second] != 0) ? ((*r).first - 1)
                               : (((*r).first + second - 1) >> 1);
  for (int i = fd(dnl); i <= dnr; i = fd(dnl)) ans[i] = now, f[i] = i + 1;
}
inline set<pair<int, int> >::iterator cov(int x) {
  set<pair<int, int> >::iterator it = seg.lower_bound(make_pair(x + 1, -1));
  --it;
  return it;
}
inline void mdf(int x) {
  kd[x] = 1;
  if (kd[x - 1] == 0 || kd[x + 1] == 0) {
    set<pair<int, int> >::iterator it = cov(x);
    int l = (*it).first, r = (*it).second;
    del(it);
    if (l + 1 < x) ins(l, x - 1);
    if (r - 1 > x) ins(x + 1, r);
  }
  if (kd[x - 1] == 1 || kd[x + 1] == 1) {
    int l = x, r = x;
    set<pair<int, int> >::iterator it;
    if (kd[x - 1] == 1) {
      if (x - 1 > 1 && kd[x - 2] == 1)
        it = cov(x - 1), l = (*it).first, del(it);
      else
        l = x - 1;
    }
    if (kd[x + 1] == 1) {
      if (x + 1 < n + 2 && kd[x + 2] == 1)
        it = cov(x + 1), r = (*it).second, del(it);
      else
        r = x + 1;
    }
    ins(l, r);
  } else {
    set<pair<int, int> >::iterator r = seg.upper_bound(make_pair(x, x)), l;
    l = r, l--;
    int tl = (*l).second, tr = (*r).first;
    if (kd[tl] == 1 && kd[tr] == 1) return;
    if (kd[tl] == -1 && kd[tr] == -1) return;
    int dnl = 2, dnr = 1;
    if (kd[tl] == 0 && kd[tr] == 0) dnl = tl + 1, dnr = tr - 1;
    if (kd[tl] == 0 && kd[tr] == 1) dnl = ((tl + tr + 1) >> 1), dnr = tr - 1;
    if (kd[tl] == 1 && kd[tr] == 0) dnl = tl + 1, dnr = ((tl + tr - 1) >> 1);
    for (int i = fd(dnl); i <= dnr; i = fd(dnl)) ans[i] = now, f[i] = i + 1;
  }
}
inline void solve(int x) {
  now = t[x];
  for (int j = 0, TP = pos[x].size(); j < TP; j++) mdf(pos[x][j]);
  res = max(res, ((*(--S.end()) + 1)) >> 1);
}
int main() {
  n = read(), kd[0] = kd[n + 3] = -1;
  for (int i = 2; i <= n + 1; i++) p[i] = t[i - 1] = read();
  p[1] = p[2], p[n + 2] = p[n + 1], f[n + 3] = n + 3;
  sort(t + 1, t + n + 1), m = unique(t + 1, t + n + 1) - t - 1;
  for (int i = 1; i <= n + 2; i++)
    pos[p[i] = lower_bound(t + 1, t + m + 1, p[i]) - t].push_back(i), f[i] = i;
  seg.insert(make_pair(1, n + 2)), f[1] = 2;
  seg.insert(make_pair(0, 0)), seg.insert(make_pair(n + 3, n + 3));
  S.insert(0), S.insert(0), S.insert(0);
  for (int i = 1; i <= m; i++) solve(i);
  ans[2] = t[p[2]], ans[n + 1] = t[p[n + 1]];
  printf("%d\n", res);
  for (int i = 2; i <= n + 1; i++) printf("%d%c", ans[i], i <= n ? ' ' : '\n');
  return 0;
}
