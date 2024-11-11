#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2007;
typedef struct {
  int x, y;
} NodeTp;
int n;
long long m;
NodeTp node[MaxN], node1[MaxN];
void Init() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &node[i].x, &node[i].y), node1[i] = node[i];
  return;
}
inline double Xielv(NodeTp a) {
  NodeTp b = node[1];
  if (a.x == b.x) return 1e10;
  return 1.0 * (a.y - b.y) / (a.x - b.x);
}
int Cmp(const void *a, const void *b) {
  double k1 = Xielv(*(NodeTp *)a);
  double k2 = Xielv(*(NodeTp *)b);
  return (k1 < k2) ? 1 : -1;
}
void Solve() {
  int i, j, k, nn, mm;
  NodeTp t;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) node[j] = node1[j];
    t = node[1], node[1] = node[i], node[i] = t;
    qsort(node + 2, n - 1, sizeof(NodeTp), Cmp);
    mm = m;
    for (j = 2; j <= n; j = k) {
      for (k = j + 1; k <= n; k++)
        if (Xielv(node[j]) != Xielv(node[k])) break;
      m += (k - j) * (n - 1 - (k - j));
    }
  }
  cout << m / 6;
  return;
}
int main() {
  Init();
  Solve();
  return 0;
}
