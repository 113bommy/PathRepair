#include <bits/stdc++.h>
using namespace std;
const int N = 22, M = (1 << 20) + 5;
long long a[N], S[M];
long long A[2005], B[2005];
long long q1[2005], q2[2005];
int n, ans, bit[M];
int f[M], ok[M], q[N];
void getque(int x, int y, long long *qq) {
  int l = 1;
  qq[1] = 0;
  for (int i = (int)(x); i <= (int)(y); i++) {
    for (int j = (int)(1); j <= (int)(l); j++) {
      A[j] = qq[j];
      B[j] = qq[j] + 2 * a[q[i]];
    }
    int p1 = 1, p2 = 1, p3 = 0;
    for (; p1 <= l || p2 <= l;)
      if (p2 > l || (p1 <= l && A[p1] < B[p2]))
        qq[++p3] = A[p1++];
      else
        qq[++p3] = B[p2++];
    l *= 2;
  }
  qq[0] = l;
}
bool check(int x) {
  if ((S[x] + bit[x] + 1) & 1) return 0;
  if (bit[x] <= 1) return 0;
  *q = *q1 = *q2 = 0;
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    if (x & (1 << i)) q[++*q] = i;
  getque(1, (*q) / 2, q1);
  getque((*q) / 2 + 1, *q, q2);
  int sum = (abs(S[x]) < bit[x]) ? -2 : 0;
  long long lo = S[x] - bit[x], ri = S[x] + bit[x];
  int l1 = q1[0], l2 = q2[0], h = 1, t = 0;
  for (int i = l1; i >= 1 && sum <= 0; --i) {
    for (; t != l2 && q2[t + 1] + q1[i] < ri; ++t)
      ;
    for (; h <= t && q2[h] + q1[i] <= lo; ++h)
      ;
    sum += t + 1 - h;
  }
  return sum > 0;
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    scanf("%lld", &a[i]);
    if (!a[i]) --n, --i;
  }
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++)
    bit[i] = bit[i / 2] + (i & 1);
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++)
    for (int j = (int)(0); j <= (int)(n - 1); j++)
      if (i & (1 << j)) S[i] += a[j];
  for (int i = (int)(1); i <= (int)((1 << n) - 1); i++)
    if (ok[i] && check(i)) {
      f[i] = 1;
      int j = (1 << n) - 1 - i;
      for (int jj = j; jj; (--jj) &= j) f[i | jj] = max(f[i | jj], f[jj] + 1);
    }
  printf("%d\n", n - f[(1 << n) - 1]);
}
