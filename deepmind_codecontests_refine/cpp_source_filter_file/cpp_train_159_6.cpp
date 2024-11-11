#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
template <class T>
T sqr(T x) {
  return x * x;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int n, k, S, t, c[MAXN], v[MAXN], g[MAXN], pos[MAXN];
long long s[MAXN];
int main() {
  scanf("%d%d%d%d", &n, &k, &S, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &c[i], &v[i]);
  }
  for (int i = 0; i < k; i++) scanf("%d", &g[i]);
  sort(g, g + k);
  pos[0] = g[0];
  for (int i = 0; i < k - 1; i++) {
    pos[i + 1] = g[i + 1] - g[i];
  }
  pos[k] = S - g[k - 1];
  sort(pos, pos + k + 1);
  s[0] = pos[0];
  for (int i = 1; i <= k; i++) {
    s[i] = s[i - 1] + pos[i];
  }
  int ans = oo;
  for (int i = 0; i < n; i++) {
    if (v[i] < pos[k]) continue;
    int can = v[i] / 2;
    int now = upper_bound(pos, pos + k + 1, can) - pos;
    now--;
    long long tot;
    if (~now)
      tot = s[now] + (s[k] - s[now]) * 2ll;
    else
      tot = s[now];
    int cur = upper_bound(pos, pos + k + 1, v[i]) - pos;
    cur--;
    long long mi = 0;
    if (~cur) mi = s[cur];
    if (~now) mi -= s[now];
    int rem = cur - now;
    long long has = (long long)rem * v[i] - mi;
    tot -= has;
    if (tot <= t) ans = min(ans, c[i]);
  }
  if (ans == oo)
    puts("-1");
  else
    printf("%d", ans);
}
