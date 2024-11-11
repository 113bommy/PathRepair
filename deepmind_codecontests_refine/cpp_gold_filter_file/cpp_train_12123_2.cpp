#include <bits/stdc++.h>
using namespace std;
int n, m, p[3005];
bool used[3005];
int c[3005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  scanf("%d", &m);
  int cycles = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      cycles++;
      for (int j = i; !used[j]; j = p[j]) used[j] = true;
    }
  }
  printf("%d\n", abs((n - m) - cycles));
  memset(used, false, sizeof(used));
  if (cycles > n - m) {
    for (int i = 1; !used[i]; i = p[i]) used[i] = true;
    for (int i = 2; i <= n && cycles > n - m; i++) {
      if (!used[i]) {
        printf("%d %d\n", 1, i);
        cycles--;
        for (int j = i; !used[j]; j = p[j]) used[j] = true;
      }
    }
  } else if (cycles < n - m) {
    for (int i = 1; i <= n && cycles < n - m; i++) {
      memset(c, 0, sizeof(c));
      int id = 1;
      for (int j = p[i]; j != i; j = p[j]) c[j] = ++id;
      c[i] = ++id;
      id = 0;
      for (int j = i + 1; j <= n && cycles < n - m; j++) {
        if (c[j] > id) {
          printf("%d %d\n", i, j);
          swap(p[i], p[j]);
          cycles++;
          id = c[j];
        }
      }
    }
  }
}
