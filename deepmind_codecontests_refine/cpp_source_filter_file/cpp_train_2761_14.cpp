#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int w, n, k, a, b, q, e, d, i, p;
int F2[N], F[N], A[N];
void update(int x, int v) {
  for (; x < N; x += x & -x) F[x] += v;
}
int query(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += F[x];
  return ans;
}
void update2(int x, int v) {
  for (; x < N; x += x & -x) F2[x] += v;
}
int query2(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += F2[x];
  return ans;
}
int main() {
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &w);
    if (w == 1) {
      scanf("%d %d", &d, &e);
      update(d, -query(d) + query(d - 1));
      update2(d, -query2(d) + query2(d - 1));
      A[d] += e;
      update(d, min(b, A[d]));
      update2(d, min(a, A[d]));
    } else {
      scanf("%d", &p);
      printf("%d", query(p - 1) + query2(n) - query2(p + k - 1));
    }
  }
}
