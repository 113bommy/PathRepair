#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int c[maxn], A[maxn], B[maxn];
int n, k, a, b, q, cmd;
void add(int *c, int p, int val) {
  for (; p <= n; p += p & -p) c[p] += val;
}
int sum(int *c, int p) {
  int ret = 0;
  for (; p; p -= p & -p) ret += c[p];
  return ret;
}
int main() {
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    int x, y;
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d%d", &x, &y);
      add(A, x, -min(c[x], a));
      add(B, x, -min(c[x], b));
      c[x] += y;
      add(A, x, min(c[x], a));
      add(B, x, min(c[x], b));
    } else {
      scanf("%d", &x);
      int ans = 0;
      ans += sum(B, x - 1);
      ans += sum(A, n) - sum(A, x + k - 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
