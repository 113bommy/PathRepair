#include <bits/stdc++.h>
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 1e9 + 5;
const long long linf = 1e18;
const double PI = acos(-1.0);
const int MAXN = 2e5 + 5;
const int N = 4e5 + 5;
int n, m, k, cnt = 0;
int mx[N * 4], add[N * 4];
set<pair<int, int> > s;
multiset<int> t;
void doadd(int cnt, int v) { add[cnt] += v, mx[cnt] += v; }
void up(int cnt) { mx[cnt] = max(mx[((cnt << 1))], mx[((cnt << 1 | 1))]); }
void down(int cnt) {
  if (add[cnt]) {
    doadd(((cnt << 1)), add[cnt]);
    doadd(((cnt << 1 | 1)), add[cnt]);
    add[cnt] = 0;
  }
}
void update(int l, int r, int nl, int nr, int v, int cnt) {
  if (l == nl && r == nr) {
    doadd(cnt, v);
    return;
  }
  down(cnt);
  if (nr <= ((l + r) / 2))
    update(l, ((l + r) / 2), nl, nr, v, ((cnt << 1)));
  else if (nl > ((l + r) / 2))
    update(((l + r) / 2) + 1, r, nl, nr, v, ((cnt << 1 | 1)));
  else
    update(l, ((l + r) / 2), nl, ((l + r) / 2), v, ((cnt << 1))),
        update(((l + r) / 2) + 1, r, ((l + r) / 2) + 1, nr, v,
               ((cnt << 1 | 1)));
  up(cnt);
}
void build(int l, int r, int cnt) {
  if (l == r) {
    mx[cnt] = l - 1;
    return;
  }
  build(l, ((l + r) / 2), ((cnt << 1))),
      build(((l + r) / 2) + 1, r, ((cnt << 1 | 1))), up(cnt);
}
int query(int l, int r, int nl, int nr, int cnt) {
  if (l == nl && r == nr) return mx[cnt];
  down(cnt);
  if (nr <= ((l + r) / 2)) return query(l, ((l + r) / 2), nl, nr, ((cnt << 1)));
  if (nl > ((l + r) / 2))
    return query(((l + r) / 2) + 1, r, nl, nr, ((cnt << 1 | 1)));
  return max(
      query(l, ((l + r) / 2), nl, ((l + r) / 2), ((cnt << 1))),
      query(((l + r) / 2) + 1, r, ((l + r) / 2) + 1, nr, ((cnt << 1 | 1))));
}
int work() {
  scanf("%d%d%d", &n, &k, &m), build(1, N, 1);
  while (m--) {
    pair<int, int> p;
    scanf("%d%d", &p.first, &p.second);
    int pos = abs(k - p.first) + p.second, f;
    if (s.find(p) == s.end())
      s.insert(p), f = 1, t.insert(pos);
    else
      s.erase(p), f = -1, t.erase(t.find(pos));
    update(1, N, 1, pos, f, 1);
    if (t.empty()) {
      printf("0\n");
      continue;
    }
    int l = max(n, *t.rbegin()), r = N, ans = r;
    while (l <= r) {
      if (query(1, N, 1, ((l + r) / 2), 1) <= ((l + r) / 2))
        ans = ((l + r) / 2), r = ((l + r) / 2) - 1;
      else
        l = ((l + r) / 2) + 1;
    }
    printf("%d\n", max(0, ans - n));
  }
  return 0;
}
int main() {
  work();
  return 0;
}
