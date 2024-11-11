#include <bits/stdc++.h>
using namespace std;
const int maxn = 2013;
struct Tseg {
  int id, l, r;
} seg[maxn];
int n;
namespace Dinit {
vector<int> w;
bool cmp_r(const Tseg &a, const Tseg &b) {
  return a.r < b.r || a.r == b.r && a.l > b.l;
}
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int o, r;
    scanf("%d%d", &o, &r);
    w.push_back(seg[i].l = o - r);
    w.push_back(seg[i].r = o + r);
    seg[i].id = i;
  }
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());
  for (int i = 1; i <= n; ++i) {
    seg[i].l = lower_bound(w.begin(), w.end(), seg[i].l) - w.begin();
    seg[i].r = lower_bound(w.begin(), w.end(), seg[i].r) - w.begin();
  }
  sort(seg + 1, seg + n + 1, cmp_r);
}
}  // namespace Dinit
namespace Dsolve {
int f[2 * maxn][2], fin[maxn];
vector<int> son[maxn];
vector<int> inseg;
int w[2 * maxn][2];
bool cmp_r(int a, int b) { return seg[a].r < seg[b].r; }
int work_in(int p) {
  inseg.clear();
  for (int i = 1; i <= p - 1; ++i)
    if (seg[i].l >= seg[p].l && seg[i].r <= seg[p].r) {
      inseg.push_back(i);
    }
  sort(inseg.begin(), inseg.end(), cmp_r);
  memset(w, 0, sizeof(w));
  vector<int>::iterator iter = inseg.begin();
  for (int i = seg[p].l; i <= seg[p].r; ++i) {
    if (i > seg[p].l) w[i][0] = w[i - 1][0], w[i][1] = w[i - 1][1];
    for (; iter != inseg.end() && i == seg[*iter].r; ++iter) {
      if (w[i][0] < w[seg[*iter].l][0] + fin[*iter] + 1) {
        w[i][0] = w[seg[*iter].l][0] + fin[*iter] + 1;
        w[i][1] = *iter;
      }
    }
  }
  for (int i = seg[p].r;; i = seg[w[i][1]].l)
    if (w[i][1])
      son[p].push_back(w[i][1]);
    else
      break;
  return w[seg[p].r][0];
}
void work() {
  int nowseg = 1;
  for (int i = 0; i <= seg[n].r; ++i) {
    if (i > 0) f[i][0] = f[i - 1][0], f[i][1] = f[i - 1][1];
    for (; i == seg[nowseg].r; ++nowseg) {
      fin[nowseg] = work_in(nowseg);
      if (f[i][0] < f[seg[nowseg].l][0] + fin[nowseg] + 1) {
        f[i][0] = f[seg[nowseg].l][0] + fin[nowseg] + 1;
        f[i][1] = nowseg;
      }
    }
  }
}
vector<int> use;
void get_in(int p) {
  use.push_back(seg[p].id);
  for (int i = 0; i < son[p].size(); ++i) {
    get_in(son[p][i]);
  }
}
void get_use(int x) {
  if (!f[x][1]) return;
  get_in(f[x][1]);
  get_use(seg[f[x][1]].l);
}
void print() {
  printf("%d\n", f[seg[n].r][0]);
  get_use(seg[n].r);
  for (int i = 0; i < use.size(); ++i) printf("%d ", use[i]);
  printf("\n");
}
void solve() {
  work();
  print();
}
}  // namespace Dsolve
int main() {
  Dinit::init();
  Dsolve::solve();
  return 0;
}
