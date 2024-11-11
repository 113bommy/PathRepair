#include <bits/stdc++.h>
using namespace std;
const int maxn = 3050;
struct Tree {
  int a, b;
  bool operator<(const Tree &yy) const { return a < yy.a; }
} A[maxn];
int n, v, ans;
int main() {
  int i, j, t1, t2;
  scanf("%d%d", &n, &v);
  for (i = 0; i < n; i++) scanf("%d%d", &A[i].a, &A[i].b);
  sort(A, A + n);
  for (i = 0; i < n; i++) {
    int s0 = 0;
    t1 = (i && A[i].a == A[i - 1].a + 1 ? t2 : v);
    t2 = v;
    for (j = i; A[j].a == A[i].a; j++) s0 += A[j].b;
    if (s0 <= t1)
      ans += s0, t1 -= s0;
    else
      ans += min(v + t1, s0), t2 -= min(v, s0 - t1), t1 = 0;
  }
  printf("%d\n", ans);
  return 0;
}
