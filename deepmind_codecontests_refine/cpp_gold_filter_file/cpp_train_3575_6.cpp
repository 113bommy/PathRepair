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
long long p;
int n, Q;
long long G, R;
long long d[100005];
long long f[100005];
struct SGT {
  int lcs, rcs;
  int value;
} v[2000005];
int tot;
void revise(int l, int r, int& p, int pos, int vals) {
  if (p == 0) p = ++tot;
  if (l == r && l == pos) return v[p].value = vals, void();
  if (pos <= ((l + r) >> 1)) revise(l, ((l + r) >> 1), v[p].lcs, pos, vals);
  if (((l + r) >> 1) + 1 <= pos)
    revise(((l + r) >> 1) + 1, r, v[p].rcs, pos, vals);
  if (v[p].lcs && v[p].rcs)
    v[p].value = min(v[v[p].lcs].value, v[v[p].rcs].value);
  if (v[p].lcs && v[p].rcs == 0) v[p].value = v[v[p].lcs].value;
  if (v[p].lcs == 0 && v[p].rcs) v[p].value = v[v[p].rcs].value;
}
int enquire(int l, int r, int p, int nl, int nr) {
  if (l > r) return n + 1;
  if (p == 0) return n + 1;
  if (nl <= l && r <= nr) return v[p].value;
  int re = n + 1;
  if (nl <= ((l + r) >> 1))
    re = min(re, enquire(l, ((l + r) >> 1), v[p].lcs, nl, nr));
  if (((l + r) >> 1) + 1 <= nr)
    re = min(re, enquire(((l + r) >> 1) + 1, r, v[p].rcs, nl, nr));
  return re;
}
int root;
inline long long calc(long long x) { return (x / p + (x % p > 0)) * p; }
int main() {
  read(n, G, R);
  p = G + R;
  for (int i = 1; i <= n + 1; i++) read(d[i]), d[i] += d[i - 1];
  for (int i = n; i >= 1; i--) {
    int l = (G + d[i]) % p, r = (R + G + d[i] - 1) % p;
    int id;
    if (l <= r)
      id = enquire(0, p - 1, root, l, r);
    else
      id =
          min(enquire(0, p - 1, root, l, p - 1), enquire(0, p - 1, root, 0, r));
    if (id == n + 1)
      f[i] = d[n + 1] - d[i];
    else
      f[i] = calc(d[id] - d[i]) + f[id];
    revise(0, p - 1, root, d[i] % p, i);
  }
  read(Q);
  while (Q--) {
    long long t;
    read(t);
    int l = (G - t % p + p) % p, r = (R + G - 1 - t % p + p) % p;
    int id;
    if (l <= r)
      id = enquire(0, p - 1, root, l, r);
    else
      id =
          min(enquire(0, p - 1, root, l, p - 1), enquire(0, p - 1, root, 0, r));
    long long ans;
    if (id == n + 1)
      ans = d[n + 1] + t;
    else
      ans = calc(t + d[id]) + f[id];
    printf("%lld\n", ans);
  }
  return 0;
}
