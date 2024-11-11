#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000000000LL;
long long a[1000000];
int cnt;
void dfs(long long x) {
  if (x > MAXN) return;
  if (x > 0) a[cnt++] = x;
  dfs(x * 10 + 4);
  dfs(x * 10 + 7);
}
long long fact[15];
int b[15], use[15];
void dfs(int k, int nb, int m, long long n) {
  if (k < 1) return;
  for (int i = 1; i <= m; ++i) {
    if (use[i]) continue;
    if (n > fact[k - 1] && !use[i])
      n -= fact[k - 1];
    else if (n <= fact[k - 1] && !use[i]) {
      b[nb] = i;
      use[i] = 1;
      dfs(k - 1, nb + 1, m, n);
      return;
    }
  }
}
bool ok(long long x) {
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  cnt = 0;
  dfs(0);
  sort(a, a + cnt);
  fact[0] = 1;
  for (int i = 1; i <= 15; ++i) fact[i] = fact[i - 1] * i;
  long long n, k;
  for (int i = 1; i < 15; ++i) b[i] = i;
  while (scanf("%I64d%I64d", &n, &k) != EOF) {
    if (n < 15 && fact[n] < k) {
      puts("-1");
      continue;
    }
    int i(0);
    for (i = 1;; ++i)
      if (fact[i] >= k) break;
    memset(use, 0, sizeof(use));
    dfs(i, 1, i, k);
    long long rt = n - i, res(0);
    for (int j = 1; j <= i; ++j) {
      long long t = b[j] + rt;
      if (ok(t) && ok(rt + j)) ++res;
    }
    i = 0;
    while (a[i] <= rt && i < cnt) ++i;
    res += i;
    printf("%I64d\n", res);
  }
  return 0;
}
