#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int maxn(1 << 21 | 1);
char ibuf[maxn], *iS, *iT, c;
int f;
inline char Getc() {
  return iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, maxn, stdin),
                     (iS == iT ? EOF : *iS++))
                  : *iS++;
}
template <class Int>
void In(Int &x) {
  for (f = 1, c = Getc(); c < '0' || c > '9'; c = Getc()) f = c == '-' ? -1 : 1;
  for (x = 0; c >= '0' && c <= '9'; c = Getc()) x = x * 10 + (c ^ 48);
  x *= f;
}
}  // namespace IO
using IO ::In;
const int maxn(1e6 + 5);
int n, e[maxn], tot, id[maxn], e2[maxn], vis[1 << 11], num, st[maxn];
long long d, k, g, pr[maxn], a[maxn], b[maxn], val[maxn][12];
long long f[2][12][1 << 11], inf, ret, v[1 << 11];
map<long long, vector<int> > mp;
map<long long, vector<int> >::iterator it;
vector<int> tmp;
inline long long Gcd(long long x, long long y) {
  return !y ? x : Gcd(y, x % y);
}
inline int Cmp(int x, int y) { return e2[x] < e2[y]; }
inline long long DP() {
  int i, j, now, cur, lst = 0, nxt = 1, s = 1 << tot, flg;
  memset(f, 63, sizeof(f)), inf = ret = f[0][0][0], f[0][0][0] = 0;
  for (i = 1; i <= num; ++i) {
    for (j = 0; j < s; ++j) v[j] = 0;
    for (j = 1; j <= tot; ++j) v[1 << (j - 1)] = val[id[i]][j];
    for (j = v[0] = 1; j < s; ++j)
      if (!v[j]) v[j] = v[j ^ (j & -j)] * v[j & -j];
    for (now = 0; now < s; ++now)
      if (vis[now] <= 50) {
        for (flg = 0, j = min(i, tot); ~j; --j) {
          f[nxt][j][now] = min(f[nxt][j][now], f[lst][j][now]);
          if (now) {
            for (cur = now & st[id[i]]; cur; cur = (cur - 1) & now)
              if (v[cur] <= k && f[lst][j][now ^ cur] != inf)
                f[nxt][j + 1][now] =
                    min(f[nxt][j + 1][now], f[lst][j][now ^ cur] + e2[id[i]]),
                           flg = 1;
          }
        }
        vis[now] += flg;
      }
    swap(lst, nxt);
  }
  for (j = 0; j <= tot; ++j)
    if (f[lst][j][s - 1] != inf) ret = min(ret, f[lst][j][s - 1] * j);
  return ret == inf ? -1 : ret;
}
int main() {
  int i, j, l;
  In(n), In(k);
  for (i = 1; i <= n; ++i) In(a[i]), g = Gcd(a[i], g);
  for (i = 1; i <= n; ++i) In(e[i]);
  for (d = 2; d * d <= g; ++d)
    if (g % d == 0) {
      if (d > k) return puts("-1"), 0;
      pr[++tot] = d;
      while (g % d == 0) g /= d;
    }
  if (g > 1) pr[++tot] = g;
  if (g > k) return puts("-1"), 0;
  for (i = 1; i <= n; ++i) {
    for (ret = a[i], j = 1; j <= tot; ++j)
      while (ret % pr[j] == 0) ret /= pr[j];
    a[i] /= ret;
  }
  for (i = 1; i <= n; ++i) mp[a[i]].push_back(e[i]);
  for (it = mp.begin(); it != mp.end(); ++it) {
    tmp = it->second, sort(tmp.begin(), tmp.end()),
    l = min(tot, (int)tmp.size());
    for (i = 0; i < l; ++i)
      e2[++num] = tmp[i], b[num] = it->first, id[num] = num;
  }
  sort(id + 1, id + num + 1, Cmp);
  for (i = 1; i <= num; ++i) {
    for (j = 1; j <= tot; ++j) val[i][j] = 1;
    for (j = 1; j <= tot; ++j)
      while (b[i] % pr[j] == 0)
        st[i] |= 1 << (j - 1), b[i] /= pr[j], val[i][j] *= pr[j];
  }
  printf("%lld\n", DP());
  return 0;
}
