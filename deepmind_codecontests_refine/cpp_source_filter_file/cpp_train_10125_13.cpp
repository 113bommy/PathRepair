#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int mx[maxn << 2], add[maxn << 2];
set<pair<int, int> > mp;
set<int> s;
int n, m, k, cnt[maxn];
void update(int rt) { mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]); }
void build(int l, int r, int rt) {
  if (l == r) {
    mx[rt] = l;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  update(rt);
}
void pushdown(int rt) {
  if (add[rt]) {
    add[rt << 1] += add[rt];
    add[rt << 1 | 1] += add[rt];
    mx[rt << 1] += add[rt];
    mx[rt << 1 | 1] += add[rt];
    add[rt] = 0;
  }
}
void mod(int l, int r, int rt, int ml, int mr, int v) {
  if (l < r) return;
  if (ml <= l && r <= mr) {
    add[rt] += v;
    mx[rt] += v;
    return;
  }
  int m = (l + r) >> 1;
  pushdown(rt);
  if (ml <= m) mod(l, m, rt << 1, ml, mr, v);
  if (m < mr) mod(m + 1, r, rt << 1 | 1, ml, mr, v);
  update(rt);
}
int query(int l, int r, int rt, int ql, int qr) {
  if (l < r) return 0;
  if (ql <= l && r <= qr) {
    return mx[rt];
  }
  int m = (l + r) >> 1, ret = 0;
  pushdown(rt);
  if (ql <= m) ret = max(ret, query(l, m, rt << 1, ql, qr));
  if (m < qr) ret = max(ret, query(m + 1, r, rt << 1 | 1, ql, qr));
  update(rt);
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  build(1, 2 * n, 1);
  for (int i = 1, tmp1, tmp2; i <= m; i++) {
    scanf("%d%d", &tmp1, &tmp2);
    pair<int, int> p = make_pair(tmp1, tmp2);
    int tmp = abs(tmp1 - k) + tmp2;
    if (!mp.count(p)) {
      mod(1, 2 * n, 1, 1, tmp - 1, 1);
      if (cnt[tmp] == 0) s.insert(tmp);
      cnt[tmp]++;
      mp.insert(p);
    } else {
      mod(1, 2 * n, 1, 1, tmp - 1, -1);
      cnt[tmp]--;
      if (cnt[tmp] == 0) s.erase(tmp);
      mp.erase(p);
    }
    if (s.size() == 0) {
      puts("0");
    } else {
      printf("%d\n", max(0, query(1, 2 * n, 1, 1, *s.rbegin()) - n));
    }
  }
}
