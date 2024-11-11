#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void remax(T &A, T B) {
  if (A < B) A = B;
}
template <class T>
inline void remin(T &A, T B) {
  if (A > B) A = B;
}
string ToString(long long num) {
  string ret;
  do {
    ret += ((num % 10) + '0');
    num /= 10;
  } while (num);
  reverse(ret.begin(), ret.end());
  return ret;
}
long long ToNumber(string s) {
  long long r = 0, p = 1;
  for (int i = s.size() - 1; i >= 0; --i) r += (s[i] - '0') * p, p *= 10;
  return r;
}
long long Gcd(long long a, long long b) {
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, long long power) {
  if (power < 0) return 0;
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, long long power, long long mod) {
  if (!power) return 1;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
int Log(long long num, long long base) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= base;
  }
  return ret;
}
int Count(long long mask) {
  int ret = 0;
  while (mask) {
    if (mask & 1) ++ret;
    mask >>= 1;
  }
  return ret;
}
struct query {
  int l;
  int r;
  int k;
  int ind;
  const bool operator<(const query &rhs) const;
} q[100000];
vector<int> adj[100000];
int color[100000];
int low[100000];
int high[100000];
int lowColor[100000];
int cCnt[100000];
int kCnt[100000];
int timer;
int sr;
void dfs(int u, int p = ~0) {
  low[u] = ++timer;
  lowColor[timer] = color[u];
  for (int &v : adj[u])
    if (v != p) dfs(v, u);
  high[u] = timer;
}
const bool query::operator<(const query &rhs) const {
  if (this->l / sr != rhs.l / sr) return this->l / sr < rhs.l / sr;
  return this->r < rhs.r;
}
void addColor(int color) { kCnt[++cCnt[color]]++; }
void removeColor(int color) { kCnt[cCnt[color]--]--; }
inline void run() {
  int ans[100000];
  int n, m, L = 0, R = ~0;
  scanf("%d%d", &n, &m);
  timer = ~0;
  sr = (int)sqrtl(n) + 1;
  for (int i = 0; i < n;) scanf("%d", color + i++);
  for (int i = 0; i < n;) --color[i++];
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[--u].emplace_back(--v);
    adj[v].emplace_back(u);
  }
  dfs(0);
  for (int i = 0; i < m; ++i) {
    int u;
    scanf("%d%d", &u, &q[i].k);
    q[i].l = low[--u];
    q[i].r = high[u];
    q[i].ind = i;
  }
  sort(q, q + m);
  for (int i = 0; i < m; ++i) {
    while (L < q[i].l) removeColor(lowColor[L++]);
    while (R > q[i].r) removeColor(lowColor[R--]);
    while (L > q[i].l) addColor(lowColor[--L]);
    while (R < q[i].r) addColor(lowColor[++R]);
    ans[q[i].ind] = kCnt[q[i].k];
  }
  for (int i = 0; i < m;) printf("%d\n", ans[i++]);
  for (int i = 0; i < n;) adj[i++].clear();
  memset(cCnt, 0, sizeof cCnt);
  memset(kCnt, 0, sizeof kCnt);
}
int main() {
  FILE *input = stdin;
  FILE *output = stdout;
  while (!feof(input)) {
    run();
    break;
  }
  return 0;
}
