#include <bits/stdc++.h>
using namespace std;
const int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0};
int main() {
  int i, j, m;
  long long n, x;
  scanf("%lld%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%lld", &x);
    while (x % 2 == 0) {
      x = x / 2 + n;
    }
    printf("%d\n", (x + 1) / 2);
  }
}
