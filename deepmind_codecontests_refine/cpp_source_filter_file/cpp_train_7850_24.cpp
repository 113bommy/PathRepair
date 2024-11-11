#include <bits/stdc++.h>
using namespace std;
int mdist;
int n;
bool g[1111][1111];
void edge(int a, int b) { g[a][b] = g[b][a] = true; }
void path(int a, int b, int dist) {
  for (int i = dist; i < mdist - 1; i++) {
    edge(a, n);
    a = n;
    n++;
  }
  edge(a, b);
}
void go(int beg, int end, int k, int dist) {
  if (k & 1) {
    path(beg, end, dist);
  }
  if (k > 1) {
    edge(beg, n);
    edge(beg, n + 1);
    edge(n, n + 2);
    edge(n + 1, n + 2);
    n += 3;
    go(n - 1, end, k / 2, dist + 2);
  }
}
int main() {
  int k;
  scanf("%d", &k);
  n = 2;
  int K = k;
  while (K > 1) {
    mdist += 2;
    K /= 2;
  }
  go(0, 1, k, 0);
  printf("%d\n", n);
  for (int i = (0); i <= (int(n) - 1); ++i) {
    for (int j = (0); j <= (int(n) - 1); ++j) printf("%c", g[i][j] ? 'Y' : 'N');
    printf("\n");
  }
  return 0;
}
