#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void read(T& x, Args&... args) {
  read(x), read(args...);
}
const long long maxn = 203000, maxB = 450;
long long n, m, q, a[maxn], tag[maxB], go[maxB][7][2], t;
long long L[maxB], R[maxB], pos[maxn];
inline long long simulate(long long l, long long r, long long j) {
  while (l <= r) {
    if (a[r] ^ j)
      r -= m + 1;
    else
      r--;
  }
  return l - r - 1;
}
inline void Build(long long b) {
  for (long long i = L[b]; i <= R[b]; ++i) a[i] ^= tag[b];
  tag[b] = 0;
  for (long long i = 0; i <= m; ++i) {
    go[b][i][0] = simulate(L[b], R[b] - i, 0);
    go[b][i][1] = simulate(L[b], R[b] - i, 1);
  }
}
inline void Modify(long long l, long long r) {
  if (pos[l] == pos[r]) {
    for (long long i = l; i <= r; ++i) a[i] ^= 1;
    Build(pos[l]);
    return;
  }
  for (long long i = pos[l] + 1; i < pos[r]; ++i) tag[i] ^= 1;
  for (long long i = l; i <= R[pos[l]]; ++i) a[i] ^= 1;
  for (long long i = L[pos[r]]; i <= r; ++i) a[i] ^= 1;
  Build(pos[l]), Build(pos[r]);
}
inline long long Query(long long l, long long r) {
  if (a[l] == tag[pos[l]]) return 1;
  if (pos[l] == pos[r]) {
    long long p = simulate(l + 1, r, tag[pos[l]]);
    return p == 0 ? 2 : 1;
  }
  long long p = simulate(L[pos[r]], r, tag[pos[r]]);
  long long cur = pos[r] - 1;
  while (cur > pos[l]) {
    p = go[pos[cur]][p][tag[cur]];
    cur--;
  }
  p = simulate(l + 1, R[pos[l]] - p, tag[pos[l]]);
  return p == 0 ? 2 : 1;
}
signed main() {
  read(n, m, q);
  t = sqrt(n + 0.5);
  long long opt, l, r, len = n / t, d;
  for (long long i = 1; i <= n; ++i) {
    read(l), a[i] = l & 1;
  }
  for (long long i = 1; i <= t; ++i) {
    L[i] = (i - 1) * len + 1;
    R[i] = i * len;
  }
  if (R[t] < n) {
    t++, L[t] = R[t - 1] + 1, R[t] = n;
  }
  for (long long i = 1; i <= t; ++i) {
    for (long long j = L[i]; j <= R[i]; ++j) pos[j] = i;
    Build(i);
  }
  while (q--) {
    read(opt, l, r);
    if (opt == 1) {
      read(d);
      if (d & 1) Modify(l, r);
    } else
      printf("%lld\n", Query(l, r));
  }
  return 0;
}
