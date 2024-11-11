#include <bits/stdc++.h>
using namespace std;
long long val[5000010], num[5000010];
long long n, k, a, b, c, d, q, op, Ans, s[1000010];
void build(long long Now, long long l, long long r) {
  if (l == r) {
    num[Now] = val[Now] = 0;
    return;
  }
  long long Mid = (l + r) >> 1;
  build(Now << 1, l, Mid);
  build(Now << 1 | 1, Mid + 1, r);
}
void insert(long long Now, long long l, long long r, long long x) {
  if (l == r) {
    num[Now] = min(b, s[x]);
    val[Now] = min(a, s[x]);
    return;
  }
  long long Mid = (l + r) >> 1;
  if (x <= Mid)
    insert(Now << 1, l, Mid, x);
  else
    insert(Now << 1 | 1, Mid + 1, r, x);
  num[Now] = num[Now << 1] + num[Now << 1 | 1];
  val[Now] = val[Now << 1] + val[Now << 1 | 1];
}
long long A(long long Now, long long l, long long r, long long x, long long y) {
  if (l >= x && r <= y) return num[Now];
  long long Mid = (l + r) >> 1, ret = 0;
  if (x <= Mid) ret += A(Now << 1, l, Mid, x, y);
  if (y > Mid) ret += A(Now << 1 | 1, Mid + 1, r, x, y);
  return ret;
}
long long B(long long Now, long long l, long long r, long long x, long long y) {
  if (l >= x && r <= y) return val[Now];
  long long Mid = (l + r) >> 1, ret = 0;
  if (x <= Mid) ret += B(Now << 1, l, Mid, x, y);
  if (y > Mid) ret += B(Now << 1 | 1, Mid + 1, r, x, y);
  return ret;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &k, &a, &b, &q);
  build(1, 1, n);
  for (long long i = 1; i <= q; i++) {
    scanf("%I64d", &op);
    if (op == 1) {
      scanf("%I64d%I64d", &c, &d);
      s[c] += d;
      insert(1, 1, n, c);
    } else {
      scanf("%I64d", &c);
      Ans = 0;
      if (c > 1) Ans += A(1, 1, n, 1, c - 1);
      ;
      if (c + k <= n) Ans += B(1, 1, n, c + k, n);
      printf("%I64d\n", Ans);
    }
  }
  return 0;
}
