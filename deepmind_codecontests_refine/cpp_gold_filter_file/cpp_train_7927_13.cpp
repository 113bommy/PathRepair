#include <bits/stdc++.h>
using namespace std;
int p[5010], w[5010], a[5010], q[5010], n, k, b[5010];
void adjust(int x, int y) {
  int P = w[b[x] ^ q[x]];
  if (P == x) return;
  if (P == y) {
    swap(p[x], p[y]), w[p[x]] = x, w[p[y]] = y;
    return;
  }
  swap(p[x], p[P]), w[p[x]] = x, w[p[P]] = P;
  swap(q[P], q[y]);
  adjust(P, y);
}
int main() {
  scanf("%d", &k);
  n = 1 << k;
  int X = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i), X ^= a[i], w[i] = p[i] = q[i] = i;
  if (X == 0)
    printf("Shi\n");
  else {
    printf("Fou\n");
    return 0;
  }
  for (int i = 0; i < n - 1; ++i)
    if (b[i] ^ a[i]) {
      b[i + 1] ^= b[i] ^ a[i];
      b[i] = a[i];
      adjust(i, i + 1);
    }
  for (int i = 0; i < n; ++i) printf("%d ", p[i]);
  putchar('\n');
  for (int i = 0; i < n; ++i) printf("%d ", q[i]);
}
