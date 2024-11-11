#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  clock_t _ = clock();
  while (scanf("%d", &n) == 1) {
    int ans;
    if (n & 1)
      ans = n / 2;
    else
      ans = n - (1 << (31 - __builtin_clz(n))) >> 1;
    printf("%d\n", ans);
  }
  return 0;
}
