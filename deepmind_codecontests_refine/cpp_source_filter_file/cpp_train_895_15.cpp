#include <bits/stdc++.h>
using namespace std;
const int maxn = 100111, maxk = 14;
int n, k, q, a[maxk][maxn];
void init() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
}
int A[maxk];
inline bool cmp(int a, int b) { return A[a] < A[b]; }
bitset<2050> b[maxn];
int calc(int x, int y) {
  static int w[maxk];
  for (int i = 1; i <= k; ++i) A[i] = a[i][y], w[i] = i;
  sort(w + 1, w + k + 1, cmp);
  int m = (1 << k) - 1;
  for (int i = 1; i <= k; ++i) {
    m ^= 1 << w[i] - 1;
    if (!b[x][m]) return A[w[i]];
  }
  assert(false);
}
void work() {
  for (int i = 1; i <= k; ++i)
    for (int j = 0; j < 1 << k; ++j) b[i][j] = j >> i - 1 & 1;
  for (int N = k; q--;) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      b[++N] = b[x] | b[y];
    else if (op == 2)
      b[++N] = b[x] & b[y];
    else
      printf("%d\n", calc(x, y));
  }
}
int main() {
  init();
  work();
  return 0;
}
