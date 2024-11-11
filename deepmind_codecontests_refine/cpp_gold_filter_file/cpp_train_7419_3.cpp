#include <bits/stdc++.h>
clock_t __t = clock();
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T& t) {
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
inline void read(T& t, Args&... args) {
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
int n;
int a[505050];
int pos[505050], cc;
pair<int, int> p[505050];
int vis[505050];
void work() {
  read(n);
  for (int i = (1); i <= (n); i++)
    read(a[i]), p[i].first = -1, p[i].second = 1e9, vis[i] = 0;
  cc = 0;
  for (int i = (1); i <= (n); i++)
    if (!a[i]) pos[++cc] = i;
  if (cc <= 1) return puts("0"), void();
  int L, R;
  if (cc & 1)
    L = pos[cc / 2], R = pos[cc / 2 + 2];
  else
    L = pos[cc / 2], R = pos[cc / 2 + 1];
  for (int i = (1); i <= (R); i++)
    if (a[i]) p[a[i]].first = i;
  for (int i = (n); i >= (L); i--)
    if (a[i]) p[a[i]].second = i;
  priority_queue<pair<int, int> > q;
  int cnt1 = 0, cnt2 = 0;
  for (int i = (R); i >= (1); i--) {
    if (a[i]) {
      if (p[a[i]].first == i) q.push(make_pair(p[a[i]].second, a[i]));
      continue;
    }
    if (!q.size()) continue;
    pair<int, int> t = q.top();
    q.pop();
    ++cnt1, vis[t.second] = 1;
  }
  for (int i = L, cur = 0; i <= n; i++)
    if (a[i] && !vis[a[i]] && i == p[a[i]].second)
      ++cur;
    else if (!a[i] && cur)
      --cur, ++cnt2;
  printf("%d\n", min(cnt1 + cnt2, cc / 2));
}
int main() {
  file();
  int T;
  read(T);
  while (T--) work();
  return 0;
}
