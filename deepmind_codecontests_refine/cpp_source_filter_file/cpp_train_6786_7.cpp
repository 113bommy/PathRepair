#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, inf = 1e9 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, p[MAXN], tot;
struct Node {
  int x, y, c;
} a[MAXN];
vector<int> s[MAXN];
pair<long long, int> Mn[MAXN << 2];
long long t[MAXN << 2];
inline void pushup(int x) { Mn[x] = min(Mn[x << 1], Mn[x << 1 | 1]); }
inline void pushr(int x, long long v) { Mn[x].first += v, t[x] += v; }
inline void pushdown(int x) {
  if (t[x]) pushr(x << 1, t[x]), pushr(x << 1 | 1, t[x]), t[x] = 0;
}
inline void insert(int x, int l, int r, int p, int v) {
  if (l == r) {
    Mn[x].first += v;
    return;
  }
  int mid = l + r >> 1;
  pushdown(x);
  (p <= mid ? insert(x << 1, l, mid, p, v)
            : insert(x << 1 | 1, mid + 1, r, p, v)),
      pushup(x);
}
inline void add(int x, int l, int r, int ql, int qr, int v) {
  if (ql > qr) return;
  if (ql <= l && r <= qr) return pushr(x, v);
  int mid = l + r >> 1;
  pushdown(x);
  if (ql <= mid) add(x << 1, l, mid, ql, qr, v);
  if (qr > mid) add(x << 1 | 1, mid + 1, r, ql, qr, v);
  pushup(x);
}
inline pair<long long, int> ask(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return Mn[x];
  int mid = l + r >> 1;
  pair<long long, int> res = make_pair((long long)1e18, 0);
  pushdown(x);
  if (ql <= mid) res = min(res, ask(x << 1, l, mid, ql, qr));
  if (qr > mid) res = min(res, ask(x << 1 | 1, mid + 1, r, ql, qr));
  return res;
}
inline void build(int x, int l, int r) {
  if (l == r) {
    Mn[x] = make_pair(-p[l], l);
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r), pushup(x);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read(), w = read();
    p[++tot] = x, p[++tot] = y, a[i] = (Node){x, y, w};
  }
  sort(p + 1, p + tot + 1), tot = unique(p + 1, p + tot + 1) - p - 1,
                            build(1, 1, tot);
  for (int i = 1; i <= n; i++)
    a[i].x = lower_bound(p + 1, p + tot + 1, a[i].x) - p,
    a[i].y = lower_bound(p + 1, p + tot + 1, a[i].y) - p;
  for (int i = 1; i <= n; i++) s[max(a[i].x, a[i].y)].push_back(i);
  long long sum = 0, ans = 0, px, py;
  int flg = 0;
  for (int i = 1; i <= tot; i++) {
    insert(1, 1, tot, i, sum);
    for (auto o : s[i])
      sum += a[o].c, add(1, 1, tot, min(a[o].x, a[o].y) + 1, i, a[o].c);
    pair<long long, int> t = ask(1, 1, tot, 1, i);
    if (sum - p[i] - t.first > ans)
      ans = sum - p[i] - t.first, px = p[i], py = p[t.second], flg = 1;
  }
  if (flg)
    cout << ans << '\n' << py << ' ' << py << " " << px << ' ' << px << "\n";
  else
    cout << 0 << "\n" << inf << " " << inf << " " << inf << ' ' << inf << '\n';
  return 0;
}
