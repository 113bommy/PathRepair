#include <bits/stdc++.h>
using namespace std;
int n, l, s;
int a[100010], S[100010];
int b[100010], tb, in[100010];
int c[100010], tc;
struct res {
  long long k;
  int q[100010];
  void out() {
    printf("%I64d\n%d", k, q[1]);
    for (int i = 2; i <= n - 1; ++i) printf(" %d", q[i]);
    printf("\n");
  }
} A, B;
inline bool cmp(int A, int B) { return a[A] < a[B]; }
res Solve(int l, int s) {
  for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + a[i];
  res ans;
  int t = 0, qie;
  long long sum1, sum2;
  if (s - 1 >= l) {
    ans.k = S[s - 1] + S[n];
    for (int i = l; i >= 1; --i) ans.q[++t] = i;
    for (int i = l + 1; i <= n; ++i)
      if (i != s) ans.q[++t] = i;
  } else {
    l = l - (s - 1);
    tb = 0;
    for (int i = s + 1; i <= n - 2; ++i) b[++tb] = i;
    sort(b + 1, b + tb + 1, cmp);
    memset(in, 0, sizeof(in));
    int tt = l;
    sum1 = sum2 = 0;
    for (int i = 1; i <= l; ++i) sum1 = sum1 + a[b[i]], in[b[i]] = 1;
    ans.k = sum1 * 2 + S[s - 1] + S[n];
    qie = n;
    for (int i = n - 1; i >= n - l; --i) {
      sum2 += a[i];
      if (in[i - 1]) {
        in[i - 1] = 0;
        sum1 -= a[i - 1];
      } else {
        while (tt > 0 && !in[b[tt]]) --tt;
        in[b[tt]] = 0;
        sum1 -= a[b[tt]];
      }
      if (sum1 * 2 + sum2 + S[s - 1] + S[n] < ans.k) {
        ans.k = sum1 * 2 + sum2 + S[s - 1] + S[n];
        qie = i;
      }
    }
    for (int i = s - 1; i >= 1; --i) ans.q[++t] = i;
    int last = s;
    tb = 0;
    for (int i = s + 1; i <= qie - 2; ++i) b[++tb] = i;
    sort(b + 1, b + tb + 1, cmp);
    tc = 0;
    for (int i = 1; i <= l - (n - qie); ++i) c[++tc] = b[i];
    sort(c + 1, c + tc + 1);
    for (int i = qie; i <= n - 1; ++i) c[++tc] = i;
    int h1 = 1, h2;
    while (h1 <= tc) {
      for (int i = last + 1; i <= c[h1] - 1; ++i) ans.q[++t] = i;
      h2 = h1;
      while (h2 < tc && c[h2 + 1] == c[h2] + 1) ++h2;
      ans.q[++t] = c[h2] + 1;
      for (int i = h2; i >= h1; --i) ans.q[++t] = c[i];
      h1 = h2 + 1;
      last = c[h2] + 1;
    }
    for (int i = last + 1; i <= n; ++i) ans.q[++t] = i;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &l, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (l == 0) {
    if (s == 1) {
      printf("%d\n%d", a[n] - a[1], 2);
      for (int i = 3; i <= n; ++i) printf(" %d", i);
      printf("\n");
    } else
      printf("-1\n");
    return 0;
  }
  if (l == n - 1) {
    if (s == n) {
      printf("%d\n%d", a[n] - a[1], n - 1);
      for (int i = n - 2; i >= 1; --i) printf(" %d", i);
      printf("\n");
    } else
      printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n - 1; ++i) a[i] = a[i + 1] - a[i];
  a[n] = 0;
  A = Solve(l, s);
  reverse(a + 1, a + n);
  B = Solve(n - l - 1, n - s + 1);
  if (A.k < B.k)
    A.out();
  else {
    for (int i = 1; i <= n; ++i) B.q[i] = n - B.q[i] + 1;
    B.out();
  }
  return 0;
}
