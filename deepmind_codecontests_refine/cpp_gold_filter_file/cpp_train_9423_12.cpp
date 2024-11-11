#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
const int MAXN = 200010;
int bit[2][MAXN];
int val[MAXN];
int n;
void update(int id, int pos, int val) {
  for (; pos < n; pos = pos | (pos + 1)) {
    bit[id][pos] += val;
  }
}
int get(int id, int r) {
  int ans = 0;
  for (; r != -1; r = (r & (r + 1)) - 1) {
    ans += bit[id][r];
  }
  return ans;
}
int get(int id, int l, int r) { return get(id, r) - get(id, l - 1); }
int main() {
  int k, a, b, q;
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  for (int i = 0; i < q; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int p, d;
      scanf("%d%d", &p, &d);
      --p;
      int add0 = max(0, min(d, b - val[p]));
      int add1 = max(0, min(d, a - val[p]));
      val[p] += d;
      update(0, p, add0);
      update(1, p, add1);
    } else if (ty == 2) {
      int p;
      scanf("%d", &p);
      --p;
      printf("%d\n", get(0, 0, p - 1) + get(1, p + k, n - 1));
    }
  }
  return 0;
}
