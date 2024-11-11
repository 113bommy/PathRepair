#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000 + 10;
const int maxT = maxN * 5;
const int inf = int(1e9 + 1e5);
int n, g, r, T;
int l[maxN];
long long t[maxN], f[maxN];
int tl[maxN], nt, q[maxN], nq;
int tree[maxT];
vector<int> qu[maxN];
int fq[maxN], ft[maxN];
void enter() {
  scanf("%d%d%d", &n, &g, &r);
  T = g + r;
  t[0] = 0;
  nt = 2;
  tl[0] = 0;
  tl[1] = T - 1;
  for (int i = 0; i <= n; i++) {
    scanf("%d", &l[i]);
    t[i + 1] = t[i] + l[i];
    tl[nt++] = t[i + 1] % T;
  }
  scanf("%d", &nq);
  for (int i = 0; i < nq; i++) scanf("%d", &q[i]);
}
void setmin(int u, int v, int lo, int hi, int i) {
  if (lo > u || hi < u) return;
  if (lo == hi && u == lo) {
    tree[i] = v;
    return;
  }
  setmin(u, v, lo, (lo + hi) / 2, i * 2);
  setmin(u, v, (lo + hi) / 2 + 1, hi, i * 2 + 1);
  tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}
int getmin(int u, int v, int lo, int hi, int i) {
  if (lo > v || hi < u) return n + 1;
  if (u <= lo && hi <= v) return tree[i];
  return min(getmin(u, v, lo, (lo + hi) / 2, i * 2),
             getmin(u, v, (lo + hi) / 2 + 1, hi, i * 2 + 1));
}
int getlb(int x) { return lower_bound(tl, tl + nt, x) - tl; }
int getub(int x) { return upper_bound(tl, tl + nt, x) - tl - 1; }
void buildTree() {
  for (int i = 0; i < maxT; i++) tree[i] = n + 1;
  for (int i = 0; i < nt; i++) qu[i].push_back(n + 1);
  for (int i = n; i >= 1; i--) qu[getlb(t[i] % T)].push_back(i);
  for (int i = 0; i < nt; i++) setmin(i, qu[i].back(), 0, nt - 1, 1);
}
int gmin(int x) {
  if (x + g >= T) return getmin(getlb(x - r), getub(x - 1), 0, nt - 1, 1);
  return min(getmin(0, getub(x - 1), 0, nt - 1, 1),
             getmin(getlb(x + g), nt - 1, 0, nt - 1, 1));
}
void init() {
  sort(tl, tl + nt);
  nt = unique(tl, tl + nt) - tl;
  buildTree();
  for (int i = 0; i < nq; i++) {
    fq[i] = gmin((T - q[i] % T) % T);
  }
  int id;
  for (int i = 1; i <= n; i++) {
    id = getlb(t[i] % T);
    qu[id].pop_back();
    setmin(id, qu[id].back(), 0, nt - 1, 1);
    ft[i] = gmin(t[i] % T);
  }
  f[n + 1] = 0;
  long long tt;
  for (int i = n; i >= 1; i--) {
    id = ft[i];
    f[i] = (tt = t[id] - t[i]) + f[id];
    if (id < n + 1) f[i] += T - tt % T;
  }
}
void solve() {
  init();
  int p;
  long long res, tt;
  for (int i = 0; i < nq; i++) {
    p = fq[i];
    res = (tt = t[p] + q[i]) + f[p];
    if (p < n + 1) res += T - tt % T;
    printf("%I64d\n", res);
  }
}
int main() {
  enter();
  solve();
  return 0;
}
