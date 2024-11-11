#include <bits/stdc++.h>
using namespace std;
void getre() {
  int x = 0;
  printf("%d\n", 1 / x);
}
void gettle() {
  int res = 1;
  while (1) res <<= 1;
  printf("%d\n", res);
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
template <typename N>
inline int sgn(N a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
inline void gn(long long &x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gn(long double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gs(char *s) { scanf("%s", s); }
inline void gc(char &c) {
  while ((c = getchar()) > 126 || c < 33)
    ;
}
inline void pc(char c) { putchar(c); }
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
const int mo = 998244353;
struct seg_tag {
  int ad;
  int mu;
};
const int SEG_MAXN = 200000 + 5;
int seglen[SEG_MAXN * 4];
int seg[SEG_MAXN * 4];
seg_tag tag[SEG_MAXN * 4];
seg_tag tag0 = (seg_tag){0, 1};
inline seg_tag operator+(seg_tag old, seg_tag ne) {
  seg_tag c;
  c.mu = 1ll * old.mu * ne.mu % mo;
  c.ad = (1ll * old.ad * ne.mu + ne.ad) % mo;
  return c;
}
inline void segadd(int x, seg_tag v) {
  seg[x] = (1ll * seg[x] * v.mu + 1ll * v.ad * seglen[x]) % mo;
  tag[x] = tag[x] + v;
}
inline void segpd(int x) {
  if (tag[x].ad != 0 || tag[x].mu != 1) {
    segadd(x << 1, tag[x]);
    segadd(x << 1 | 1, tag[x]);
    tag[x] = tag0;
  }
}
inline void segpu(int x) { seg[x] = (seg[x << 1] + seg[x << 1 | 1]) % mo; }
void seginit_in(int l, int r, int x) {
  tag[x] = tag0;
  seglen[x] = r - l + 1;
  if (l == r) {
    seg[x] = 0;
  } else {
    int mid = l + r >> 1;
    seginit_in(l, mid, x << 1);
    seginit_in(mid + 1, r, x << 1 | 1);
    segpu(x);
  }
}
int l1, r1;
int sans;
bool ans_bo;
seg_tag stag;
void segupd_in(int l, int r, int x) {
  if (l1 <= l && r <= r1) {
    segadd(x, stag);
  } else {
    int mid = l + r >> 1;
    segpd(x);
    if (l1 <= mid) segupd_in(l, mid, x << 1);
    if (r1 > mid) segupd_in(mid + 1, r, x << 1 | 1);
    segpu(x);
  }
}
void segque_in(int l, int r, int x) {
  if (l1 <= l && r <= r1) {
    if (!ans_bo)
      ans_bo = 1, sans = seg[x];
    else
      sans = (sans + seg[x]) % mo;
  } else {
    int mid = l + r >> 1;
    segpd(x);
    if (l1 <= mid) segque_in(l, mid, x << 1);
    if (r1 > mid) segque_in(mid + 1, r, x << 1 | 1);
  }
}
int segn;
void segupd(int l, int r, seg_tag v) {
  if (l > r) return;
  stag = v, l1 = l, r1 = r;
  segupd_in(1, segn, 1);
}
int segque(int l, int r) {
  if (l > r) return 0;
  ans_bo = 0, l1 = l, r1 = r;
  segque_in(1, segn, 1);
  return sans;
}
void seginit(int n) {
  segn = n;
  seginit_in(1, segn, 1);
}
set<pair<int, int> > second[222222];
seg_tag mu, ad;
void gao(int l, int r, set<pair<int, int> > &second) {
  if (l > r) return;
  auto nex = second.lower_bound(make_pair(l + 1, -100));
  int rr = min(r, nex->first - 1);
  if (nex->second == -1) {
    segupd(l, rr, mu);
  } else
    segupd(l, rr, ad);
  gao(rr + 1, r, second);
}
void shan(int l, int r, set<pair<int, int> > &second) {
  auto nex = second.lower_bound(make_pair(r + 2, -100));
  auto pre = second.upper_bound(make_pair(l, -100));
  pre--;
  int lefs = pre->second;
  int rigs = nex->second;
  while (1) {
    auto t = second.lower_bound(make_pair(l, -100));
    if (t->first > r + 1) break;
    second.erase(t);
  }
  if (lefs == -1) second.insert(make_pair(l, 1));
  if (rigs == 1) second.insert(make_pair(r + 1, -1));
}
int main() {
  int n, q;
  gn(n);
  gn(q);
  seginit(n);
  mu.ad = 0;
  mu.mu = 2;
  ad.ad = 1;
  ad.mu = 1;
  for (int i = (1), _ed = (n + 1); i < _ed; i++) {
    second[i].insert(make_pair(n + 2, 1));
    second[i].insert(make_pair(-1, -1));
  }
  while (q--) {
    int t;
    gn(t);
    if (t == 1) {
      int l, r, x;
      gn(l);
      gn(r);
      gn(x);
      gao(l, r, second[x]);
      shan(l, r, second[x]);
    } else {
      int l, r;
      gn(l);
      gn(r);
      printf("%d\n", segque(l, r));
    }
  }
  return 0;
}
