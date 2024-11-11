#include <bits/stdc++.h>
using namespace std;
char str[2][25][15];
int main() {
  int n, m, q, x;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %s", str[0][i]);
  for (int i = 0; i < m; i++) scanf(" %s", str[1][i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    --x;
    printf("%s%s\n", str[0][x % n], str[1][x % m]);
  }
  return 0;
}
