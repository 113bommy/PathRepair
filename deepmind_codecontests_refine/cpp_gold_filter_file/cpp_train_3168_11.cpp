#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 4e6 + 5;
const double eps = 1e-9;
using namespace std;
int n, m, w;
long long BIT[4][MAXN];
void add(int fl, int x, long long u, long long v) {
  int lim = fl <= 1 ? n : m;
  for (int i = x; i <= lim; i += i & -i) BIT[fl][i] += u * v;
}
long long calc(int fl, int x) {
  int lim = fl <= 1 ? n : m;
  long long ret = 0;
  for (int i = x; i > 0; i -= i & -i) ret += BIT[fl][i];
  return ret;
}
int main() {
  scanf("%d", &(n)), scanf("%d", &(m)), scanf("%d", &(w));
  long long sum = 0;
  for (int i = 0; i < w; i++) {
    int t, x1, y1, x2, y2, v;
    scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
    if (t == 0) {
      scanf("%d", &(v));
      add(0, x1, y2 - y1 + 1, v);
      add(1, x1, 1ll * (y2 - y1 + 1) * x1, v);
      add(0, x2 + 1, -(y2 - y1 + 1), v);
      add(1, x2 + 1, -1ll * (y2 - y1 + 1) * (x2 + 1), v);
      add(2, y1, x2 - x1 + 1, v);
      add(3, y1, 1ll * (x2 - x1 + 1) * y1, v);
      add(2, y2 + 1, -(x2 - x1 + 1), v);
      add(3, y2 + 1, -1ll * (x2 - x1 + 1) * (y2 + 1), v);
      sum += (x2 - x1 + 1) * (y2 - y1 + 1) * v;
    } else {
      long long tmp = (calc(0, x2) * (x2 + 1) - calc(1, x2));
      tmp -= (calc(0, x1 - 1) * x1 - calc(1, x1 - 1));
      tmp += (calc(2, y2) * (y2 + 1) - calc(3, y2));
      tmp -= (calc(2, y1 - 1) * y1 - calc(3, y1 - 1));
      printf("%I64d\n", (tmp - sum));
    }
  }
  return 0;
}
