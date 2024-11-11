#include <bits/stdc++.h>
using namespace std;
const int maxn = 212345;
struct Seg {
  int l, r, v, lzy;
} T[maxn << 2];
int n, m, p;
pair<int, int> weapons[maxn], armors[maxn];
tuple<int, int, int> monsters[maxn];
vector<pair<int, int> > events[maxn * 5];
void push_up(int o) { T[o].v = max(T[o << 1].v, T[o << 1 | 1].v); }
void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else {
    T[o].v = -weapons[l].second;
  }
}
void push_down(int o) {
  T[o << 1].lzy += T[o].lzy;
  T[o << 1].v += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o << 1 | 1].v += T[o].lzy;
  T[o].lzy = 0;
}
void add(int o, int l, int r, int x) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += x;
    T[o].lzy += x;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, x);
  if (r > mi) add(o << 1 | 1, l, r, x);
  push_up(o);
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int(i) = (1); (i) <= (n); (i)++) {
    int a, ca;
    scanf("%d%d", &a, &ca);
    weapons[i] = {a, ca};
  }
  for (int(i) = (1); (i) <= (m); (i)++) {
    int b, cb;
    scanf("%d%d", &b, &cb);
    armors[i] = {b, cb};
  }
  for (int(i) = (1); (i) <= (p); (i)++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    monsters[i] = {x, y, z};
  }
  sort(weapons + 1, weapons + n + 1);
  int j = 0;
  for (int(i) = (1); (i) <= (n); (i)++)
    if (weapons[i].first != weapons[i - 1].first) weapons[++j] = weapons[i];
  n = j;
  sort(armors + 1, armors + m + 1);
  j = 0;
  for (int(i) = (1); (i) <= (m); (i)++)
    if (armors[i].first != armors[i - 1].first) armors[++j] = armors[i];
  m = j;
  for (int(i) = (1); (i) <= (p); (i)++)
    events[get<1>(monsters[i])].emplace_back(get<0>(monsters[i]),
                                             get<2>(monsters[i]));
  for (int(i) = (1); (i) <= (1e6); (i)++)
    if (!events[i].empty()) sort((events[i]).begin(), (events[i]).end());
  build(1, 1, n);
  j = 0;
  int ans = -2e9 - 10;
  for (int(i) = (1); (i) <= (m); (i)++) {
    int b = armors[i].first, cb = armors[i].second;
    while (j < b) {
      for (auto [x, z] : events[j]) {
        if (x >= weapons[n].first) break;
        int pos =
            lower_bound(weapons + 1, weapons + n + 1, make_pair(x + 1, -1)) -
            weapons;
        add(1, pos, n, z);
      }
      j++;
    }
    int now = T[1].v - cb;
    ans = max(ans, now);
  }
  printf("%d", ans);
}
