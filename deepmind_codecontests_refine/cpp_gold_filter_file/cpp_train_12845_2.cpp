#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n * (n - 1) / 2 <= m) {
    puts("no solution");
    return 0;
  }
  for (int i = (1); i <= (n); ++i) {
    printf("%d %d\n", 0, i);
  }
  return 0;
}
