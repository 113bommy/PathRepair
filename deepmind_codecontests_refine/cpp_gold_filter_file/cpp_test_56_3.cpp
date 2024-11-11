#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, mod = 1e9 + 7;
inline long long input() {
  char c = getchar();
  long long o;
  bool f = 0;
  while (c > 57 || c < 48) f |= (c == '-'), c = getchar();
  for (o = 0; c > 47 && c < 58; c = getchar())
    o = (o << 1) + (o << 3) + (c - 48);
  return f ? -o : o;
}
int KSM(int v, long long t) {
  int ret = 1;
  while (t) {
    if (t & 1) ret = 1LL * ret * v % mod;
    t >>= 1;
    v = 1LL * v * v % mod;
  }
  return ret;
}
int co[200], cnt = 0, C[MAXN], dp[MAXN][6];
map<long long, int> mp;
priority_queue<long long> Q;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void DP(long long u, int p, int c, int son) {
  int cls = 0, crs = 0;
  if (mp.count((u << 1))) {
    int pls = mp[(u << 1)];
    for (int i = 0; i <= 5; i++)
      if (i + c != 5 && i != c) add(cls, dp[pls][i]);
  } else
    cls = son;
  if (mp.count((u << 1 | 1))) {
    int prs = mp[(u << 1 | 1)];
    for (int i = 0; i <= 5; i++)
      if (i + c != 5 && i != c) add(crs, dp[prs][i]);
  } else
    crs = son;
  dp[p][c] = 1LL * cls * crs % mod;
}
int main() {
  long long n = input(), m = input();
  co['w'] = 0;
  co['y'] = 5;
  co['g'] = 1;
  co['b'] = 4;
  co['r'] = 2;
  co['o'] = 3;
  memset(C, -1, sizeof(C));
  for (int i = 1; i <= m; i++) {
    long long u = input();
    mp[u] = ++cnt;
    C[mp[u]] = co[getchar()];
    Q.emplace(u);
  }
  while (Q.size()) {
    long long u = Q.top(), tu = u, p = mp[u];
    int t = n, son;
    Q.pop();
    while (tu) {
      tu >>= 1;
      t--;
    }
    son = KSM(4, (1LL << t) - 1);
    if (~C[p])
      DP(u, p, C[p], son);
    else
      for (int i = 0; i <= 5; i++) DP(u, p, i, son);
    if ((u >> 1) && (mp.count(u >> 1) == 0))
      mp[u >> 1] = ++cnt, Q.emplace(u >> 1);
  }
  int res = 0, p1 = mp[1];
  for (int i = 0; i <= 5; i++) add(res, dp[p1][i]);
  printf("%d\n", res);
}
