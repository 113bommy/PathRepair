#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 1e9 + 7;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
int n;
long long a[100005];
vector<pair<int, int> > ask[100005];
const long long INF = 2e9;
int Q;
int top;
int r_lim[100005];
long long t_val[100005];
long long p_val[100005];
long long len[100005];
long long P[100005], iP[100005];
long long nsf[100005];
long long sum[100005];
void merge(int x, int y) {
  if (len[x] > 31 && t_val[y] > 0 || t_val[x] + (t_val[y] << len[x]) >= INF)
    t_val[x] = INF;
  else
    t_val[x] = t_val[x] + (t_val[y] << len[x]);
  t_val[x] = min(INF, t_val[x]);
  p_val[x] = (p_val[x] + p_val[y] * P[len[x]] % p) % p;
  len[x] += len[y];
  r_lim[x] = r_lim[y];
  sum[x] = (sum[x - 1] + p_val[x]) % p;
}
inline long long calc(int l) {
  int id = lower_bound(r_lim + 1, r_lim + top + 1, l) - r_lim;
  long long ans = (sum[top] - sum[id] + p) * 2 % p;
  long long ans2 = (nsf[r_lim[id]] - nsf[l - 1] + p) % p * iP[l - 1] % p;
  return (ans + ans2) % p;
}
long long ans[100005];
int main() {
  read(n, Q);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1, x, y; i <= Q; i++)
    read(x, y), ask[y].push_back(make_pair(x, i));
  P[0] = 1;
  for (int i = 1; i <= 100000; i++) P[i] = P[i - 1] * 2 % p;
  iP[0] = 1;
  for (int i = 1; i <= 100000; i++) iP[i] = iP[i - 1] * 500000004 % p;
  for (int i = 1; i <= n; i++)
    nsf[i] = (nsf[i - 1] + (a[i] % p + p) % p * P[i - 1] % p) % p;
  for (int i = 1; i <= n; i++) {
    top++;
    r_lim[top] = i;
    t_val[top] = a[i];
    p_val[top] = (a[i] % p + p) % p;
    len[top] = 1;
    sum[top] = (sum[top - 1] + p_val[top]) % p;
    while (top > 1 && t_val[top] >= 0)
      merge(top - 1, top), top--, sum[top + 1] = 0;
    for (auto as : ask[i]) ans[as.second] = calc(as.first);
  }
  for (int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
  return 0;
}
