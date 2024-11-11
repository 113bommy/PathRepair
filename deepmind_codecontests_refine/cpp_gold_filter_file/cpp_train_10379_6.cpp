#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
const int Maxn = 1 << 17;
const int inf = 0x3f3f3f3f;
class seg {
 public:
  int cur;
  int t;
  int color;
  int l, r;
  seg(int CUR = -1, int T = -1, int COLOR = -1, int L = -1, int R = -1) {
    cur = CUR;
    t = T;
    color = COLOR;
    l = L;
    r = R;
  }
  bool operator<(const seg& o) const {
    if (cur < o.cur) return true;
    if (cur > o.cur) return false;
    if (t < o.t) return true;
    if (t > o.t) return false;
    if (t == 0) return color > o.color;
    if (t == 1) return color < o.color;
  }
};
class node {
 public:
  int max_unmarked;
  int min_color;
  set<int> colors;
  node() {
    max_unmarked = -1;
    min_color = -1;
    colors.clear();
  }
  void insert(int x) { colors.insert(x); }
  void erase(int x) { colors.erase(x); }
  void print() {
    printf("max and min %d %d\n", max_unmarked, min_color);
    for (auto v : colors) printf("%d ", v);
    cout << "\n";
    cout << "\n";
  }
};
int n;
vector<int> y;
bool mark[Maxn];
seg sg[Maxn << 1];
node tr[Maxn << 2];
int MN;
void print() {
  for (int i = 0; i <= 6; i++) {
    tr[i].print();
  }
  tr[9].print();
  tr[10].print();
  tr[13].print();
  tr[14].print();
}
void input() {
  scanf("%d", &n);
  y.push_back(-inf);
  y.push_back(inf);
  sg[0] = seg(-inf, 1, 0, -inf, inf);
  sg[1] = seg(inf, 0, 0, -inf, inf);
  for (int i = 1; i <= n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    y.push_back(y1);
    y.push_back(y2);
    sg[(i << 1)] = seg(x1, 0, i, y1, y2);
    sg[(i << 1) | 1] = seg(x2, 1, i, y1, y2);
  }
  sort((y).begin(), (y).end());
  y.resize(unique((y).begin(), (y).end()) - y.begin());
  MN = y.size();
  sort(sg, sg + (n << 1) + 2);
}
void recalc(int p, int l, int r) {
  tr[p].min_color = -1;
  tr[p].max_unmarked = -1;
  if (r - l > 1) {
    int mi = (l + r) >> 1;
    if (tr[((p << 1) + 1)].max_unmarked != -1 &&
        mark[tr[((p << 1) + 1)].max_unmarked])
      recalc(((p << 1) + 1), l, mi);
    if (tr[((p << 1) + 2)].max_unmarked != -1 &&
        mark[tr[((p << 1) + 2)].max_unmarked])
      recalc(((p << 1) + 2), mi, r);
    tr[p].min_color =
        min(tr[((p << 1) + 1)].min_color, tr[((p << 1) + 2)].min_color);
    tr[p].max_unmarked =
        max(tr[((p << 1) + 1)].max_unmarked, tr[((p << 1) + 2)].max_unmarked);
  }
  if (!tr[p].colors.empty()) {
    int top = *(tr[p].colors.rbegin());
    tr[p].min_color = max(tr[p].min_color, top);
    if (tr[p].max_unmarked < top) {
      if (!mark[top] && top == tr[p].min_color) {
        tr[p].max_unmarked = top;
      } else
        tr[p].max_unmarked = -1;
    }
  }
}
void update(int c, int t, int a, int b, int p, int l, int r) {
  if (a >= y[r] || b <= y[l]) return;
  if (a <= y[l] && b >= y[r]) {
    if (t == 0)
      tr[p].insert(c);
    else
      tr[p].erase(c);
    recalc(p, l, r);
    return;
  }
  int mi = (l + r) >> 1;
  update(c, t, a, b, ((p << 1) + 1), l, mi);
  update(c, t, a, b, ((p << 1) + 2), mi, r);
  recalc(p, l, r);
}
void update(int c, int t, int a, int b) {
  update(c, t, a, b, 0, 0, MN - 1);
  while (tr[0].max_unmarked != -1) {
    mark[tr[0].max_unmarked] = true;
    recalc(0, 0, MN - 1);
  }
}
void solve() {
  for (int i = 0; i < (n << 1) + 2; i++) {
    update(sg[i].color, sg[i].t, sg[i].l, sg[i].r);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
    if (mark[i]) ans++;
  printf("%d\n", ans);
}
int main() {
  input();
  solve();
  return 0;
}
