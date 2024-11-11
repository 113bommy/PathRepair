#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  long long k;
  while (~scanf("%d%I64d", &n, &k)) {
    long long t = (long long)n * (n - 1) / 2;
    if (k >= t) {
      printf("no solution\n");
      continue;
    }
    int y = 1;
    for (i = 0; i < n; i++) printf("%d %d\n", 0, y), y++;
  }
  return 0;
}
