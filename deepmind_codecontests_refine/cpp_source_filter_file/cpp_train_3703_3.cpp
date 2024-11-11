#include <bits/stdc++.h>
using namespace std;
int c[200000] = {0}, n, edge[200000], x[200000], y[200000];
void bicoloring(int i) {
  if (c[edge[i]] == 0) {
    c[edge[i]] = 3 - c[i];
    bicoloring(edge[i]);
  }
  if (c[i ^ 2] == 0) {
    c[i ^ 2] = 3 - c[i];
    bicoloring(i ^ 2);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    --x[i], --y[i];
    edge[x[i]] = y[i], edge[y[i]] = x[i];
  }
  for (int i = 0; i < 2 * n; ++i) {
    if (!c[i]) {
      c[i] = 1;
      bicoloring(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", c[x[i]], c[y[i]]);
  }
}
