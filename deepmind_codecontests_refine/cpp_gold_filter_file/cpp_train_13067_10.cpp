#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, p;
  bool operator<(const node &_) const { return x < _.x; }
} A[200010];
int stk[200010], R[200010];
int main() {
  int d, n, m, i;
  scanf("%d%d%d", &d, &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &A[i].x, &A[i].p);
  }
  A[++m] = (node){0, (0x3f3f3f3f)};
  A[++m] = (node){d, 0};
  sort(A, A + 1 + m);
  for (i = 1; i <= m; i++) {
    if (A[i].x - A[i - 1].x > n) {
      printf("-1\n");
      return 0;
    }
  }
  int Top = 0;
  for (i = m; i >= 1; i--) {
    while (Top > 0 && A[i].p < A[stk[Top]].p) {
      Top--;
    }
    R[i] = stk[Top];
    stk[++Top] = i;
  }
  long long Ans = 0;
  int now = n;
  for (i = 1; i < m; i++) {
    int dis = A[R[i]].x - A[i].x;
    if (dis > n) {
      Ans += 1LL * A[i].p * (n - now);
      now = n;
      now -= A[i + 1].x - A[i].x;
    } else {
      int t = max(0, dis - now);
      Ans += 1LL * t * A[i].p;
      now += t;
      now -= dis;
      i = R[i] - 1;
    }
  }
  printf("%lld\n", Ans);
  return 0;
}
