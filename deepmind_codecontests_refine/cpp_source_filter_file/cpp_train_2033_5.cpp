#include <bits/stdc++.h>
using namespace std;
int a[1010000], n, q0;
int main() {
  scanf("%d%d", &n, &q0);
  int op, d;
  int c0 = 0, c1 = 0;
  bool z = false;
  for (int i = 1; i <= q0; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &d);
      d = (d % n + n) % n;
      if (d & 1)
        swap(c0, c1), z ^= 1, c0 += (d + 1) / 2, c1 += d / 2;
      else
        c0 += d / 2, c1 += d / 2;
    } else
      swap(c0, c1), z ^= 1;
  }
  for (int i = 0; i <= n - 1; ++i) {
    bool t = z ^ (i & 1);
    if (t)
      a[(i / 2 + c1) % (n / 2) * 2 + 1] = i;
    else
      a[(i / 2 + c0) % (n / 2) * 2] = i;
  }
  for (int i = 0; i <= n - 1; ++i) printf("%d ", a[i] + 1);
  return 0;
}
