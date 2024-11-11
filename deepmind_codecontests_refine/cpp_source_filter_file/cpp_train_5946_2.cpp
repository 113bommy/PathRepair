#include <bits/stdc++.h>
using namespace std;
const int SIZE = 550;
long long w[300111], sum[300111], res[300111];
struct Query {
  int a, b, num;
} q[300111];
bool cmp(Query a, Query b) { return a.b < b.b; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &q[i].a, &q[i].b);
    q[i].num = i;
  }
  sort(q, q + m, cmp);
  for (int i = 0; i < m;) {
    if (q[i].b > SIZE) {
      long long ans = 0;
      for (int j = q[i].a; j < m; j += q[i].b) ans += w[j];
      res[q[i].num] = ans;
      i++;
    } else {
      int x = q[i].b;
      for (int j = n; j > 0; j--)
        if (j + x > n)
          sum[j] = w[j];
        else
          sum[j] = sum[j + x] + w[j];
      while (i < m && q[i].b == x) {
        res[q[i].num] = sum[q[i].a];
        i++;
      }
    }
  }
  for (int i = 0; i < m; i++) printf("%I64d\n", res[i]);
}
