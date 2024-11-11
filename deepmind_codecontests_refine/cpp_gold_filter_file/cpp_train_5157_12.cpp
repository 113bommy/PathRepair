#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  while (~scanf("%d", &n)) {
    for (int i = 0; i <= n; i++) {
      scanf("%d %d", &x, &y);
    }
    printf("%d\n", (n - 4) / 2);
  }
}
