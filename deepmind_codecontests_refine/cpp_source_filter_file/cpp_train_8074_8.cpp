#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, y;
int main() {
  scanf("%d", &n);
  if (n <= 31620)
    printf("%d %d %d", n, n + 1, n * (n + 1));
  else
    printf("-1");
  return 0;
}
