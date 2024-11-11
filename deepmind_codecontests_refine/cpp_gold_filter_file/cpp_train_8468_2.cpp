#include <bits/stdc++.h>
using namespace std;
int grid[1000][1000];
int r[1000], c[1000];
int main() {
  int n, m, k, a, b;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    r[i] = i;
    for (int j = 0; j < m; j++) scanf("%d", &grid[i][j]), c[j] = j;
  }
  char op;
  while (k--) {
    cin >> op >> a >> b;
    if (op == 'g')
      printf("%d\n", grid[r[a - 1]][c[b - 1]]);
    else if (op == 'c')
      swap(c[a - 1], c[b - 1]);
    else
      swap(r[a - 1], r[b - 1]);
  }
}
