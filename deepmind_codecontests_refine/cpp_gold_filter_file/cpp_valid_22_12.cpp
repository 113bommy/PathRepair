#include <bits/stdc++.h>
const int N = 40;
const int K = 10;
int n, k, q[K], a[K][N], cur[K + 1][N];
bool run(int op) {
  if (n == 1) return true;
  if (!op)
    memset(cur[0], -1, n << 2);
  else
    memcpy(cur[op], cur[op - 1], n << 2);
  if (op == k) {
    for (int i = 0; i < n; ++i)
      if (cur[op][i] == -1 || i && cur[op][i] < cur[op][i - 1]) return false;
    return true;
  }
  int in[2] = {0, 0};
  for (int i = 0; i < q[op]; ++i)
    if (cur[op][a[op][i]] != -1) ++in[cur[op][a[op][i]]];
  for (int i = 0; i < in[0]; ++i) cur[op][a[op][i]] = 0;
  for (int i = in[0]; i < q[op]; ++i) cur[op][a[op][i]] = 1;
  if (!run(op + 1)) return false;
  for (int i = in[0]; i < q[op] - in[1]; ++i) {
    cur[op][a[op][i]] = 0;
    if (!run(op + 1)) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", q + i);
    for (int j = 0; j < q[i]; ++j) {
      scanf("%d", a[i] + j);
      --a[i][j];
    }
  }
  if (run(0))
    printf("ACCEPTED\n");
  else
    printf("REJECTED\n");
  return 0;
}
