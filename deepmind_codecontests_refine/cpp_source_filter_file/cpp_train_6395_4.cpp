#include <bits/stdc++.h>
using namespace std;
int n, p;
void doit() {
  scanf("%d%d", &n, &p);
  int s = 0, m = 2 * n + p;
  if (n * (n - 1) / 2 == m) {
    printf("%d %d\n", 1, 2);
    s++;
  }
  for (int i = 3; i <= n; i++) {
    printf("%d %d\n", 1, i);
    printf("%d %d\n", 2, i);
    s++;
  }
  if (s == m) return;
  for (int i = 3; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      printf("%d %d\n", i, j);
      s++;
      if (s == m) return;
    }
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) doit();
}
