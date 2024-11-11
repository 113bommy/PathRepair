#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int P = 1e9 + 7;
const int inf = 1e9;
const long long Inf = 1e15;
inline int IN() {
  char ch = getchar();
  int x = 0, f = 0;
  while (ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  }
  return f ? (-x) : x;
}
inline int Pow(int x, int y, int p) {
  int an = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) an = (long long)an * x % p;
  return an;
}
void renew(int &x, int y) {
  x += y;
  if (x < 0)
    x += P;
  else if (x >= P)
    x -= P;
}
void setIO(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
template <typename T>
inline void chkmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void chkmax(T &a, const T &b) {
  if (a < b) a = b;
}
int n;
long long a[N];
inline int cmp(const long long &a, const long long &b) { return a >= b; }
map<pair<int, long long>, long long> mps;
long long dp(int x, long long v) {
  if (x >= n) return v * n;
  if (v == 0) return 0;
  if (mps.count(make_pair(x, v))) return mps[make_pair(x, v)];
  x++;
  if (v >= a[x]) {
    long long now = v % a[x];
    long long &res = mps[make_pair(x - 1, v)];
    res = 0;
    res = max(res, dp(x, now) + (v - now) * (x - 1));
    res = max(res, dp(x, a[x] - 1) + (v - now - a[x]) * (x - 1));
    return res;
  } else {
    int nxt = lower_bound(a + x, a + n + 1, v, cmp) - a;
    if (nxt > n) return v * n;
    long long now = v % a[nxt];
    long long &res = mps[make_pair(x, v)];
    res = 0;
    res = max(res, dp(nxt, now) + (v - now) * (nxt - 1));
    res = max(res, dp(nxt, a[nxt] - 1) + (v - now - a[nxt]) * (nxt - 1));
    return res;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (int)1; i <= (int)n; i++) scanf("%lld", a + i);
  for (int i = (int)2; i <= (int)n; i++) a[i] = min(a[i], a[i - 1]);
  printf("%lld\n", dp(1, a[1] - 1));
  return 0;
}
