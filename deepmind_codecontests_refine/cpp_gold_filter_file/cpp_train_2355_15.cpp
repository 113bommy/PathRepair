#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x7fffffffffffffff;
const int dir[5][2] = {0, 0, -1, 0, 1, 0, 0, -1, 0, 1};
const int M = 33;
int n, x;
int main() {
  scanf("%d%d", &n, &x);
  if (n == 1)
    printf("YES\n%d\n", x);
  else if (n == 2) {
    if (x)
      printf("YES\n0 %d", x);
    else
      printf("NO\n");
  } else {
    printf("YES\n");
    for (int i = 0; i < n - 3; ++i) printf("%d ", i), x ^= i;
    printf("%d %d %d", (1 << 18) ^ x, (1 << 19), (1 << 18) ^ (1 << 19));
  }
  return 0;
}
