#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
int n, k, a, b, q;
struct fenwick {
  int limit, cur[maxn];
  long long fw[maxn];
  void update(int x, int v) {
    v = min(limit - cur[x], v);
    cur[x] += v;
    for (; x < maxn; x += x & -x) fw[x] += v;
  }
  long long get(int x, int y) {
    long long ret = 0;
    for (x--; x; x &= x - 1) ret -= fw[x];
    for (; y; y &= y - 1) ret += fw[y];
    return ret;
  }
} fwb, fwa;
int main() {
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  fwb.limit = b;
  fwa.limit = a;
  for (int i = 1, type, a, b; i <= q; i++) {
    scanf("%d%d", &type, &a);
    if (type == 1) {
      scanf("%d", &b);
      fwa.update(a, b);
      fwb.update(a, b);
    } else {
      long long ans = 0;
      ans += fwb.get(1, a - 1);
      ans += fwa.get(a + k, n);
      cout << ans << endl;
    }
  }
  return 0;
}
