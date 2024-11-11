#include <bits/stdc++.h>
const int MAXN = 5e5 + 10;
using namespace std;
inline long long in() {
  long long x = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * flag;
}
int n, m;
long long a[MAXN];
struct Node {
  int l, r, id;
} qry[MAXN];
bool cmp(Node x, Node y) { return x.r < y.r; }
const long long MOD = 1e9 + 7;
long long sum[MAXN], l[MAXN], r[MAXN], top;
long long presum[MAXN], sum2[MAXN], pw2[MAXN], ans[MAXN];
void merge(int x) {
  long long nowl = x, nowr = x, nowsum = a[x];
  while (nowsum > 0 && top >= 1) {
    long long len = nowl - l[top];
    if (len > 31 || nowsum > MOD || ((nowsum << len) + sum[top] > MOD))
      nowsum =
          ((nowsum % MOD * pw2[len] % MOD + sum[top]) % MOD + MOD) % MOD + MOD;
    else
      nowsum = (nowsum << len) + sum[top];
    nowl = l[top];
    --top;
  }
  ++top;
  l[top] = nowl;
  r[top] = nowr;
  sum[top] = nowsum;
  presum[top] = ((presum[top - 1] + sum[top]) % MOD + MOD) % MOD;
}
long long calc(int x, int y) {
  return ((sum2[x] - sum2[y + 1] * pw2[y - x + 1] % MOD) % MOD + MOD) % MOD;
}
int main() {
  n = in();
  m = in();
  pw2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = in();
    pw2[i] = pw2[i - 1] * 2 % MOD;
  }
  for (int i = n; i >= 1; --i)
    sum2[i] = ((sum2[i + 1] * 2 % MOD + a[i]) % MOD + MOD) % MOD;
  for (int i = 1; i <= m; ++i) qry[i] = (Node){(int)in(), (int)in(), i};
  sort(qry + 1, qry + m + 1, cmp);
  for (int i = 1, j = 1; i <= n; ++i) {
    merge(i);
    while (qry[j].r == i && j <= m) {
      int pos = lower_bound(r + 1, r + top + 1, qry[j].l) - r;
      ans[qry[j].id] = (((presum[top] - presum[pos] + MOD) % MOD * 2 % MOD +
                         calc(qry[j].l, r[pos])) %
                            MOD +
                        MOD) %
                       MOD;
      ++j;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
