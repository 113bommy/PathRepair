#include <bits/stdc++.h>
using namespace std;
long long a[200010], b[200010];
int n, k, x, fl, i, tmp;
inline int cmp(int x, int y) { return abs(a[x]) > abs(a[y]); }
int main() {
  scanf("%d%d%d", &n, &k, &x);
  for (i = fl = 1; i <= n; i++)
    scanf("%I64d", &a[i]), fl *= ((a[i] < 0) ? -1 : 1), b[i] = i;
  make_heap(b + 1, b + 1 + n, cmp);
  while (k--) {
    tmp = fl * ((a[b[1]] < 0) ? -1 : 1);
    a[b[1]] -= tmp * x;
    fl = tmp * ((a[b[1]] < 0) ? -1 : 1);
    pop_heap(b + 1, b + n + 1, cmp);
    push_heap(b + 1, b + 1 + n, cmp);
  }
  for (i = 1; i <= n; i++) printf("%I64d ", a[i]);
}
