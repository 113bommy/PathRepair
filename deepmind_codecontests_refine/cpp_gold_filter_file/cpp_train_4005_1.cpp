#include <bits/stdc++.h>
int x4[4] = {0, 0, -1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int xhorse[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int yhorse[8] = {2, 1, -2, -1, 2, 1, -2, -1};
using namespace std;
int n;
long long l, r;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%I64d %I64d", &l, &r);
    long long ans = l;
    for (int i = 0; i < 64; i++) {
      if (ans & (1LL << i)) continue;
      long long coba = ans | (1LL << i);
      if (coba <= r && coba >= 0LL)
        ans = coba;
      else
        break;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
