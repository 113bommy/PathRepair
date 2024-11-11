#include <bits/stdc++.h>
using namespace std;
void reloc() {
  freopen("/Users/admin/Desktop/cards.in", "r", stdin);
  freopen("/Users/admin/Desktop/cards.out", "w", stdout);
  return;
}
const int maxn = 100000, maxq = 200000, maxt = maxn * 3, inf = 10000000;
struct rect {
  int i;
  bool ok;
  int x1, x2, y1, y2;
  bool operator<(const rect b) const { return i < b.i; }
};
struct event {
  bool type;
  int x1, x2, y1, y2, k;
  bool operator<(const event b) const {
    if (x2 != b.x2) return x2 < b.x2;
    return type < b.type;
  }
} e[maxq * 2 + 1];
int n, m, k, q, up;
pair<int, int> ro[maxq + 1];
rect re[maxq + 1];
struct segtree {
  int mini[maxt + 1];
  void init() { memset(mini, 0, sizeof(mini)); }
  void upd(int x) {
    mini[x] = min(mini[(x << 1)], mini[((x << 1) + 1)]);
    return;
  }
  void update(int p, int v, int x = 1, int l = 1, int r = 0) {
    if (r == 0) r = up;
    if (p > r || p < l) return;
    if (l == r) {
      mini[x] = v;
      return;
    }
    update(p, v, (x << 1), l, ((l + r) >> 1));
    update(p, v, ((x << 1) + 1), ((l + r) >> 1) + 1, r);
    upd(x);
    return;
  }
  int qu(int le, int ri, int x = 1, int l = 1, int r = 0) {
    if (r == 0) r = up;
    if (r < le || ri < l) return inf;
    if (le <= l && r <= ri) {
      return mini[x];
    }
    return min(qu(le, ri, (x << 1), l, ((l + r) >> 1)),
               qu(le, ri, ((x << 1) + 1), ((l + r) >> 1) + 1, r));
  }
} t;
void read() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &ro[i].first, &ro[i].second);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &re[i].x1, &re[i].y1, &re[i].x2, &re[i].y2);
    re[i].i = i;
    re[i].ok = 0;
  }
  return;
}
void makexbased() {
  for (int i = 1; i <= k; i++) {
    e[i].type = 0;
    e[i].x2 = ro[i].first;
    e[i].y2 = ro[i].second;
  }
  for (int i = 1; i <= q; i++) {
    int j = i + k;
    e[j].type = 1;
    e[j].k = i;
    e[j].x1 = re[i].x1;
    e[j].x2 = re[i].x2;
    e[j].y1 = re[i].y1;
    e[j].y2 = re[i].y2;
  }
  up = m;
  return;
}
void makeybased() {
  for (int i = 1; i <= k; i++) {
    e[i].type = 0;
    e[i].x2 = ro[i].second;
    e[i].y2 = ro[i].first;
  }
  for (int i = 1; i <= q; i++) {
    int j = i + k;
    e[j].type = 1;
    e[j].k = i;
    e[j].x1 = re[i].y1;
    e[j].x2 = re[i].y2;
    e[j].y1 = re[i].x1;
    e[j].y2 = re[i].x2;
  }
  up = n;
  return;
}
void solve() {
  t.init();
  sort(e + 1, e + 1 + k + q);
  for (int i = 1; i <= k + q; i++) {
    if (e[i].type) {
      if (t.qu(e[i].y1, e[i].y2) >= e[i].x1) re[e[i].k].ok = 1;
    } else {
      t.update(e[i].y2, e[i].x2);
    }
  }
  return;
}
void print() {
  sort(re + 1, re + 1 + q);
  for (int i = 1; i <= q; i++) {
    if (re[i].ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return;
}
void work() {
  makexbased();
  solve();
  makeybased();
  solve();
  print();
  return;
}
int main() {
  read();
  work();
  return 0;
}
