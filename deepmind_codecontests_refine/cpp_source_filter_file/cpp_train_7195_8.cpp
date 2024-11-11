#include <bits/stdc++.h>
using namespace std;
inline int re_ad() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
int n, k, q;
int a[400010], b[400010], c[400010];
int sum[400010], id[400010], L[400010], f[400010], cnt;
int num[1010][33000], ans, tot;
const int K = 400;
inline void change1(int p, int v) {
  register int i;
  if (!v) return;
  for (i = p; i <= n; i += k) {
    sum[i] ^= v;
    if (sum[i] == 0) --ans;
    if (sum[i] == v) ++ans;
  }
  i = p % k + ((n - p % k) / k) * k;
  if (sum[i] == 0) --tot;
  if (sum[i] == v) ++tot;
}
void change2(int p, int v) {
  for (int i = p; id[i] == id[p]; i += k) {
    if (v && (sum[i] ^ f[id[p]]) == 0) ++ans;
    num[id[p]][sum[i]]--;
    sum[i] ^= v;
    num[id[p]][sum[i]]++;
    if (v && (sum[i] ^ f[id[p]]) == 0) --ans;
  }
  for (int i = id[p] + 1; i <= cnt && L[i] % k == p % k; ++i) {
    if (v) ans += num[i][f[i]];
    f[i] ^= v;
    if (v) ans -= num[i][f[i]];
  }
  int lst = p % k + ((n - p % k) / k) * k;
  if (v && (sum[lst] ^ f[id[lst]]) == 0) --tot;
  if (v && (sum[lst] ^ f[id[lst]]) == v) ++tot;
}
inline void change(int pla, int nu) {
  if (n / k < K)
    change1(pla, nu ^ c[pla]);
  else
    change2(pla, nu ^ c[pla]);
  c[pla] = nu;
}
int main() {
  register int i, j;
  char s[5];
  n = re_ad();
  k = re_ad();
  q = re_ad();
  for (i = 1; i <= n; ++i) a[i] = re_ad();
  for (i = 1; i <= n; ++i) b[i] = re_ad();
  ++n;
  if (n / k >= K) {
    for (i = 1; i <= k; ++i)
      for (j = 1; j <= n; j += k) {
        if (((j - 1) / k + 1) % K == 1) {
          L[++cnt] = j;
          num[cnt][0] = min(K, (n - j) / k + 1);
        }
        id[j] = cnt;
      }
  }
  for (i = 1; i <= n; ++i) change(i, (a[i] ^ a[i - 1]) ^ (b[i] ^ b[i - 1]));
  if (tot)
    puts("-1");
  else
    printf("%d\n", ans);
  while (q--) {
    scanf("%s", s + 1);
    i = re_ad();
    j = re_ad();
    if (s[1] == 'a')
      a[i] = j;
    else
      b[i] = j;
    change(i, a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1]);
    if (i != n) ++i, change(i, a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1]);
    if (tot)
      puts("-1");
    else
      printf("%d\n", ans);
  }
}
