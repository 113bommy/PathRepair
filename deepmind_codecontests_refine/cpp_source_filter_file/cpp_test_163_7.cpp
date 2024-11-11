#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
typedef struct {
  int n;
  vector<pair<int, long long> > a[N];
  set<int> s[N];
} Matrix;
Matrix a;
inline long long quick_pow(long long x, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans;
}
inline vector<pair<int, long long> >::iterator get1(int x, int y) {
  return lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll));
}
inline vector<pair<int, long long> >::iterator get2(int x, int y) {
  auto ans = lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll));
  if (ans == a.a[x].end() || ans->first != y) {
    ans = a.a[x].insert(
        lower_bound(a.a[x].begin(), a.a[x].end(), make_pair(y, 0ll)),
        make_pair(y, 0ll));
    a.s[y].insert(x);
  }
  return ans;
}
inline void gauss(Matrix &a, int mod) {
  int ni = a.n + 1;
  for (register int i = 1; i <= a.n; i++) {
    long long cur_inv;
    auto p = get1(i, i);
    if (p->second == 0) {
      int t;
      for (register int j = i + 1; j <= a.n; j++) {
        auto p = get1(j, i);
        if (p == a.a[j].end()) break;
        if (p->first != j) j = p->first;
        if (p->second != 0) {
          t = j;
          break;
        }
      }
      swap(a.a[i], a.a[t]);
    }
    p = get1(i, i);
    cur_inv = quick_pow(p->second, mod - 2, mod);
    for (register int j = i + 1; j <= a.n; j++) {
      auto nxt = a.s[i].lower_bound(j);
      if (nxt == a.s[i].end()) break;
      if (*nxt != j) j = *nxt;
      auto p = get1(j, i);
      if (p == a.a[j].end()) break;
      if (p->first != i || p->second == 0) continue;
      long long t = cur_inv * p->second % mod;
      for (register int k = i; k <= ni; k++) {
        auto qq = get1(i, k);
        if (qq == a.a[i].end()) break;
        if (qq->first != k) k = qq->first;
        if (qq->second == 0) continue;
        auto pp = get2(j, k);
        pp->second = ((pp->second - t * qq->second % mod) % mod + mod) % mod;
      }
    }
  }
  for (register int i = a.n; i >= 1; i--) {
    auto p = get1(i, ni);
    for (register int j = i + 1; j <= a.n; j++) {
      auto pp = get1(i, j);
      if (pp == a.a[i].end()) break;
      if (pp->first != j) j = pp->first;
      p->second =
          ((p->second - get2(i, j)->second * get2(j, ni)->second % mod) % mod +
           mod) %
          mod;
    }
    p->second = p->second * quick_pow(get1(i, i)->second, mod - 2, mod) % mod;
  }
}
int x[100007], y[100007], pos[100007];
set<tuple<int, int, int, int> > s;
int main() {
  int t;
  cin >> t;
  for (register int i = 1; i <= t; i++) {
    int n, m, rb, cb, rd, cd, p, loop = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    int tx = rb, ty = cb;
    int dr = 1, dc = 1;
    s.clear();
    while (true) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      loop++;
      x[loop] = rb;
      y[loop] = cb;
      rb += dr;
      cb += dc;
      auto tp = make_tuple(rb, cb, dr, dc);
      if (s.count(tp)) {
        loop--;
        break;
      }
      s.insert(tp);
    }
    int cnt = 0;
    for (register int i = 1; i <= loop; i++) {
      if (x[i] == rd || y[i] == cd) pos[++cnt] = i;
    }
    a.n = cnt;
    memset(a.a, 0, sizeof(a.a));
    long long fuck = (100 - p) * quick_pow(100, mod - 2, mod) % mod;
    for (register int i = 1; i <= cnt; i++) {
      a.a[i].clear();
      a.s[i].clear();
    }
    for (register int i = 1; i <= cnt; i++) {
      int pre = i == 1 ? cnt : i - 1;
      int dis = i == 1 ? (loop - pos[cnt] + 1) + pos[i] - 1 : pos[i] - pos[pre];
      get2(i, pre)->second = 1;
      auto p = get2(i, i);
      p->second = (p->second + mod - fuck) % mod;
      get2(i, cnt + 1)->second = fuck * dis % mod;
    }
    gauss(a, mod);
    cout << (get1(1, cnt + 1)->second + pos[1] - 1) % mod << endl;
  }
  return 0;
}
