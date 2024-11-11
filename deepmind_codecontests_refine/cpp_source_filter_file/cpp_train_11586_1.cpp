#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  ++k;
  int a[8];
  int b[] = {0, 0};
  memset(a, 0, sizeof(a));
  int i, j;
  for (i = (0); i < (n); ++i) {
    char buf[128];
    scanf("%s", buf);
    int x[] = {-1, -1, -1};
    for (j = (0); j < (m); ++j) {
      int pos = 2;
      if (buf[j] == 'G') pos = 0;
      if (buf[j] == 'R') pos = 1;
      x[pos] = j;
    }
    if (x[2] == -1) continue;
    if (x[0] == -1 && x[1] == -1) continue;
    if (x[0] == -1 || x[1] == -1) {
      if (x[0] == -1)
        b[1] = 1;
      else
        b[0] = 1;
      continue;
    }
    int diff = abs(x[0] - x[1]) - 1;
    for (j = (0); j < (8); ++j) {
      a[j] += diff % k;
      a[j] %= k;
      diff /= k;
    }
  }
  int sum = 0;
  for (i = (0); i < (8); ++i) sum += a[i];
  if (b[0] != 0 && b[1] != 0) {
    printf("Draw\n");
    return 0;
  }
  if (b[0] != 0 || b[1] != 0) {
    printf("%s\n", b[0] != 0 ? "First" : "Second");
    return 0;
  }
  printf("%s\n", sum != 0 ? "First" : "Second");
  return 0;
};
