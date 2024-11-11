#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005], b[300005], p[300005];
long long s[300005];
int stk[300005], t;
int q1[300005], q2[300005], q3[300005], q;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (n); ++i) scanf("%d", a + i), p[i] = i;
  for (int i = 1; i <= (n); ++i) scanf("%d", b + i);
  sort(p + 1, p + n + 1, [](int i, int j) { return a[i] < a[j]; });
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= (n); ++i) a[i] = b[i] - a[i];
  for (int i = 1; i <= (n); ++i) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= (n); ++i)
    if (s[i] < 0) return puts("NO"), 0;
  if (s[n]) return puts("NO"), 0;
  for (int i = 1; i <= (n); ++i) {
    if (a[i] > 0) stk[++t] = i;
    if (a[i] < 0) {
      int d = -a[i];
      while (t && a[stk[t]] <= d)
        q1[++q] = stk[t], q2[q] = i, d -= q3[q] = a[stk[t--]];
      if (d) q1[++q] = stk[t], q2[q] = i, a[stk[t]] -= q3[q] = d;
    }
  }
  printf("YES\n%d\n", q);
  for (int i = 1; i <= (q); ++i)
    printf("%d %d %d\n", p[q1[i]], p[q2[i]], q3[i]);
  return 0;
}
