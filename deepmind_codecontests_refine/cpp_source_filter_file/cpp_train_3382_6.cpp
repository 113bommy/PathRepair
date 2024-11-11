#include <bits/stdc++.h>
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T first, T second) {
  return uniform_int_distribution<T>(first, second)(rng);
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n, T, _cnt;
pair<int, int> D[403030 >> 1];
int _w[403030 >> 1];
void init() {
  static int first[403030], second[403030], p[403030], _l[403030], _r[403030];
  for (int i = (1); i <= (n); i++)
    read(first[i], second[i]), chkmax(first[i], 0);
  int m = 0, K = 0;
  for (int i = (1); i <= (n); i++)
    if (second[i] >= first[i] && second[i] - first[i] < 2 * T - 2)
      p[++m] = first[i], p[++m] = second[i], ++K, _l[K] = first[i],
      _r[K] = second[i];
    else if (second[i] >= first[i])
      ++_cnt;
  sort(p + 1, p + m + 1);
  m = unique(p + 1, p + m + 1) - p - 1;
  n = K;
  for (int i = (1); i <= (n); i++) first[i] = _l[i], second[i] = _r[i];
  for (int i = (1); i <= (n); i++)
    first[i] = lower_bound(p + 1, p + m + 1, first[i]) - p,
    second[i] = lower_bound(p + 1, p + m + 1, second[i]) - p;
  long long dt = p[1];
  p[1] = 0;
  for (int i = (2); i <= (m); i++)
    if ((p[i] -= dt) > p[i - 1] + 2 * T)
      dt += p[i] - (p[i - 1] + 2 * T), p[i] = p[i - 1] + 2 * T;
  for (int i = (1); i <= (n); i++)
    D[i] = make_pair(p[first[i]], p[second[i]] + 1);
  sort(D + 1, D + n + 1);
  for (int i = (1); i <= (n); i++) {
    int second = D[i].second;
    int x = lower_bound(D + 1, D + n + 1, make_pair(second, -1)) - D;
    ++_w[i], --_w[x];
  }
  for (int i = (1); i <= (n); i++) _w[i] += _w[i - 1];
}
vector<pair<int, int> > Dec[403030 << 1];
struct hh {
  int tp, ti, first, second;
  hh(int a, int b, int c, int d) { tp = a, ti = b, first = c, second = d; }
  const bool operator<(const hh &a) const {
    return ti == a.ti ? tp < a.tp : ti < a.ti;
  }
};
vector<hh> op[403030 << 1];
vector<pair<int, int> > inc[403030 << 1];
const int Tree = 403030 * 35;
int ch[Tree][2], mx[Tree], cc;
int root[403030 << 1];
void add(int &k, int first, int second, int x, int y, int w) {
  if (!k) return;
  int kk = k;
  k = ++cc;
  ch[k][0] = ch[kk][0], ch[k][1] = ch[kk][1], mx[k] = mx[kk];
  if (x <= first && second <= y) return mx[k] += w, void();
  int tg = mx[k] - max(mx[ch[k][0]], mx[ch[k][1]]), mid = (first + second) >> 1;
  if (x <= mid) add(ch[k][0], first, mid, x, y, w);
  if (y > mid) add(ch[k][1], mid + 1, second, x, y, w);
  mx[k] = tg + max(mx[ch[k][0]], mx[ch[k][1]]);
}
int query(int k, int first, int second, int x, int y) {
  if (!k) return -1e7;
  if (x <= first && second <= y) return mx[k];
  int tg = mx[k] - max(mx[ch[k][0]], mx[ch[k][1]]), mid = (first + second) >> 1,
      res = -1e7;
  if (x <= mid) chkmax(res, query(ch[k][0], first, mid, x, y));
  if (y > mid) chkmax(res, query(ch[k][1], mid + 1, second, x, y));
  return res + tg;
}
void modify(int &k, int first, int second, int x, int w) {
  int kk = k;
  k = ++cc;
  mx[k] = mx[kk], ch[k][0] = ch[kk][0], ch[k][1] = ch[kk][1];
  if (first == second) return chkmax(mx[k], w), void();
  int mid = (first + second) >> 1;
  int tg = (ch[k][0] || ch[k][1]) ? mx[k] - max(mx[ch[k][0]], mx[ch[k][1]]) : 0;
  w -= tg;
  if (x <= mid)
    modify(ch[k][0], first, mid, x, w);
  else
    modify(ch[k][1], mid + 1, second, x, w);
  mx[k] = max(mx[ch[k][0]], mx[ch[k][1]]) + tg;
}
vector<pair<int, int> > V[3];
void rebuild(int k, int first, int second, int tg, int tp) {
  if (!k) return;
  if (first == second) return V[tp].push_back(make_pair(first, tg + mx[k]));
  int mid = (first + second) >> 1;
  tg += mx[k] - max(mx[ch[k][0]], mx[ch[k][1]]);
  rebuild(ch[k][0], first, mid, tg, tp),
      rebuild(ch[k][1], mid + 1, second, tg, tp);
}
void Rebuild(int second) {
  int first = max(0, second - 2);
  for (int i = (0); i <= (2); i++) V[i].clear();
  for (int i = (first); i <= (second); i++)
    rebuild(root[i], 0, T - 1, 0, i - first);
  cc = 0;
  for (int i = (first); i <= (second); i++) {
    root[i] = 0;
    for (auto t : V[i - first]) modify(root[i], 0, T - 1, t.first, t.second);
  }
}
int main() {
  file();
  read(n, T);
  init();
  for (int i = (1); i <= (n); i++) {
    op[D[i].first / T].push_back(hh(i, D[i].first % T, 0, 0));
    if (D[i].second - D[i].first > T) {
      auto add = [&](int first, int second, int re) {
        Dec[first / T].push_back(
            make_pair(first % T, (second % T == 0 ? T : second % T))),
            op[re / T].push_back(hh(-1, re % T, first, second));
      };
      int first = D[i].first, second = D[i].second - T;
      if (first % T < second % T || second % T == 0)
        add(first, second, D[i].second);
      else
        add(first, first - first % T + T, D[i].second),
            add(second - second % T, second, D[i].second);
    }
    int first = D[i].first, second = D[i].second;
    while (first - first % T + T <= second)
      inc[first / T].push_back(make_pair(first % T, T)),
          first = first - first % T + T;
    if (first < second)
      inc[first / T].push_back(make_pair(first % T, second % T));
  }
  mx[0] = -1e7;
  const int RE = n / 10;
  int ti = 0;
  for (int i = (0); i <= (4 * n); i++) {
    if (i) root[i] = root[i - 1];
    for (auto p : inc[i]) {
      add(root[i], 0, T - 1, p.first, p.second - 1, 1);
      if ((++ti) > RE) ti = 0, Rebuild(i);
    }
    sort(op[i].begin(), op[i].end());
    for (auto p : op[i]) {
      ++ti;
      if (p.tp == -1)
        add(root[p.first / T], 0, T - 1, p.first % T,
            (p.second % T == 0 ? T - 1 : p.second % T - 1), 1);
      else {
        int x = p.ti, w = 0;
        if (i > 0) chkmax(w, query(root[i - 1], 0, T - 1, 0, x));
        if (i > 1) chkmax(w, mx[root[i - 2]]);
        modify(root[i], 0, T - 1, x, w + _w[p.tp]);
      }
      if (ti > RE) ti = 0, Rebuild(i);
    }
    for (auto p : Dec[i]) {
      add(root[i], 0, T - 1, p.first, p.second - 1, -1);
      if ((++ti) > RE) ti = 0, Rebuild(i);
    }
  }
  cout << max(0, mx[root[n * 4]]) + _cnt;
  return 0;
}
