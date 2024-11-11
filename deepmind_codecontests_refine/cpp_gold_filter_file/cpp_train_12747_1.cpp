#include <bits/stdc++.h>
using namespace std;
long long tree[1050000], f[1050000], ss[1050000];
long long mf[300300], ms[300300], fib[300300], qfib[300300];
long long a[300300], qmf[300300], qms[300300];
void ini(long long s, long long e, long long node) {
  if (s == e) {
    tree[node] = a[s];
    return;
  }
  long long lft = node << 1, rht = (node << 1) | 1, mid = (s + e) >> 1;
  ini(s, mid, lft);
  ini(mid + 1, e, rht);
  tree[node] = (tree[lft] + tree[rht]) % 1000000009;
  return;
}
long long S, E, x, y;
void update(long long s, long long e, long long node) {
  if (S > e || s > E) return;
  if (S <= s && e <= E) {
    f[node] = (f[node] + fib[s - S + 1]) % 1000000009;
    ss[node] = (ss[node] + fib[s - S + 2]) % 1000000009;
    tree[node] = (tree[node] +
                  (qfib[e - S + 1] - qfib[s - S] + 1000000009) % 1000000009) %
                 1000000009;
    return;
  }
  long long lft = node << 1, rht = (node << 1) | 1, mid = (s + e) >> 1;
  update(s, mid, lft);
  update(mid + 1, e, rht);
  tree[node] = (tree[lft] + tree[rht]) % 1000000009;
  x = e - s + 1;
  tree[node] = (tree[node] + (f[node] * qmf[x]) % 1000000009 +
                (ss[node] * qms[x]) % 1000000009) %
               1000000009;
  return;
}
long long qry(long long s, long long e, long long node, long long frst,
              long long scnd) {
  if (s > E || S > e) return 0;
  if (S <= s && e <= E) {
    x = e - s + 1;
    long long ret = (tree[node] + (frst * qmf[x]) % 1000000009 +
                     (scnd * qms[x]) % 1000000009) %
                    1000000009;
    return ret;
  }
  long long lft = node << 1, rht = (node << 1) | 1, mid = (s + e) >> 1;
  long long ret, x = mid + 2 - s;
  long long F = (frst + f[node]) % 1000000009;
  long long Sc = (scnd + ss[node]) % 1000000009;
  long long nxt =
      ((F * mf[x]) % 1000000009 + (Sc * ms[x]) % 1000000009) % 1000000009;
  x++;
  long long nxt2 =
      ((F * mf[x]) % 1000000009 + (Sc * ms[x]) % 1000000009) % 1000000009;
  ret = qry(s, mid, lft, F, Sc);
  ret = (ret + qry(mid + 1, e, rht, nxt, nxt2)) % 1000000009;
  return ret;
}
int main() {
  fib[1] = fib[2] = 1;
  mf[1] = 1, mf[2] = 0;
  ms[1] = 0, ms[2] = 1;
  for (long long i = 3; i <= 300030; i++) {
    mf[i] = (mf[i - 1] + mf[i - 2]) % 1000000009;
    ms[i] = (ms[i - 1] + ms[i - 2]) % 1000000009;
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000009;
  }
  for (long long i = 1; i <= 300030; i++) {
    qmf[i] = (mf[i] + qmf[i - 1]) % 1000000009;
    qms[i] = (ms[i] + qms[i - 1]) % 1000000009;
    qfib[i] = (qfib[i - 1] + fib[i]) % 1000000009;
  }
  long long n, m, t;
  scanf("%I64d %I64d", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  ini(1, n, 1);
  while (m--) {
    scanf("%I64d %I64d %I64d", &t, &S, &E);
    if (t == 1)
      update(1, n, 1);
    else
      printf("%I64d", qry(1, n, 1, 0, 0)), printf("\n");
  }
  return 0;
}
