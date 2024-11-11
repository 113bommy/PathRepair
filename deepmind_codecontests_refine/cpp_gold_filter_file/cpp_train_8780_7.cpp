#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long mod[2] = {233, 23};
long long read() {
  long long x = 0, f = 1;
  char s = getchar();
  for (; s > '9' || s < '0'; s = getchar())
    if (s == '-') f = -1;
  for (; s >= '0' && s <= '9'; s = getchar()) x = x * 10 + s - '0';
  return x * f;
}
long long n, m, pos[N], a[N], b[N];
long long my_pow[2][N];
namespace seg {
struct node {
  long long siz, tot[2];
} e[N << 2];
long long cnt;
void pushup(long long rt) {
  e[rt].siz = e[rt << 1].siz + e[rt << 1 | 1].siz;
  e[rt].tot[0] = (e[rt << 1].tot[0] * my_pow[0][e[rt << 1 | 1].siz + 1] +
                  e[rt << 1 | 1].tot[0]) %
                 998244353;
  e[rt].tot[1] = (e[rt << 1].tot[1] * my_pow[1][e[rt << 1 | 1].siz + 1] +
                  e[rt << 1 | 1].tot[1]) %
                 1000000009;
}
void update(long long l, long long r, long long id, long long k, long long rt) {
  if (l == r) {
    if (k == -1)
      e[rt].siz = e[rt].tot[0] = e[rt].tot[1] = 0;
    else
      e[rt].siz = 1, e[rt].tot[0] = e[rt].tot[1] = k;
    return;
  }
  long long mid = (l + r) >> 1;
  if (id <= mid)
    update(l, mid, id, k, rt << 1);
  else
    update(mid + 1, r, id, k, rt << 1 | 1);
  pushup(rt);
}
}  // namespace seg
int main() {
  n = read(), m = read();
  my_pow[1][1] = my_pow[0][1] = 1;
  for (long long i = 2; i <= n + 1; ++i) {
    my_pow[0][i] = my_pow[0][i - 1] * mod[0] % 998244353;
    my_pow[1][i] = my_pow[1][i - 1] * mod[1] % 1000000009;
  }
  for (long long i = 1; i <= n; ++i) a[i] = read();
  for (long long i = 1; i <= m; ++i) b[i] = read();
  long long hash[2] = {0, 0}, tmp[2] = {0, 0};
  for (long long i = 1; i <= n; ++i) {
    hash[0] = (hash[0] * mod[0] + a[i]) % 998244353;
    hash[1] = (hash[1] * mod[1] + a[i]) % 1000000009;
    tmp[0] = (tmp[0] * mod[0] + 1) % 998244353;
    tmp[1] = (tmp[1] * mod[1] + 1) % 1000000009;
  }
  for (long long i = 1; i <= m; ++i) pos[b[i]] = i;
  long long ans = 0;
  for (long long i = 1; i <= m; ++i) {
    if (i > n) seg::update(1, m, pos[i - n], -1, 1);
    seg::update(1, m, pos[i], i, 1);
    if (i >= n &&
        seg::e[1].tot[0] == (tmp[0] * (i - n) + hash[0]) % 998244353 &&
        seg::e[1].tot[1] == (tmp[1] * (i - n) + hash[1]) % 1000000009)
      ans++;
  }
  cout << ans << "\n";
  return 0;
}
