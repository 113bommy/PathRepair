#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
static inline int bsr(unsigned x) { return 31 ^ clz(x); }
static inline int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int val[65536], nxt[65536];
bool vis[65536], in[65536];
int q = 1999;
void query(int i) {
  assert(i > 0);
  if (vis[i]) return;
  cout << "? " << i << endl;
  cin >> val[i] >> nxt[i];
  if (nxt[i] == -1 && val[i] == -1) exit(0);
  vis[i] = true;
  --q;
  if (nxt[i] > 0) in[nxt[i]] = true;
}
void answer(int y) {
  cout << "! " << y << endl;
  exit(0);
}
int main() {
  canhazfast();
  int n, start, x, i;
  int ans = 1234567890;
  mt19937_64 rng(time(nullptr));
  vector<int> ids;
  cin >> n >> start >> x;
  i = start;
  ids.resize(n);
  iota((ids).begin(), (ids).end(), 1);
  shuffle((ids).begin(), (ids).end(), rng);
  while (i > 0 && q > 1000 && !ids.empty()) {
    query(i);
    if (val[i] >= x) break;
    int j = ids.back();
    ids.pop_back();
    query(j);
    if (val[j] > x)
      ans = min(ans, val[j]);
    else if (val[i] < val[j])
      i = j;
  }
  while (i > 0) {
    query(i);
    if (val[i] > x) answer(val[i]);
    i = nxt[i];
  }
  answer(-1);
  return 0;
}
