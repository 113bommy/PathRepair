#include <bits/stdc++.h>
using namespace std;
long long s[300010];
struct fff {
  int x, y, id;
  long long s;
} pp[300010];
bool cmp1(fff a, fff b) { return a.y < b.y; }
bool cmp2(fff a, fff b) { return a.id < b.id; }
long long sum[300010];
int main() {
  int n, m;
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%I64d", &s[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &pp[i].x, &pp[i].y);
    pp[i].id = i;
  }
  int limit = sqrt(n) + 1;
  int mark = -1;
  int x, y, k;
  sort(pp, pp + m, cmp1);
  for (int i = 0; i < m; i++) {
    pp[i].s = 0;
    if (pp[i].y >= limit) {
      for (int j = pp[i].x; j <= n; j += pp[i].y) pp[i].s += s[j];
    } else {
      x = pp[i].x;
      y = pp[i].y;
      if (mark != pp[i].y) {
        mark = pp[i].y;
        for (int i = 1; i <= n; i++) sum[i] = sum[max(0, i - y)] + s[i];
      }
      k = (n - x) / y;
      pp[i].s = sum[x + k * y] - sum[x] + s[x];
    }
  }
  sort(pp, pp + m, cmp2);
  for (int i = 0; i < m; i++) printf("%I64d\n", pp[i].s);
  return 0;
}
