#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32000000")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 100050;
const int M = 20000;
int main() {
  int g, r, b;
  int ans = 0;
  scanf("%d%d%d", &g, &r, &b);
  int mn = min(g, min(r, b));
  for (int i = 0; i < min(3, mn); i++) {
    int tmp = i;
    tmp += (g - i) / 3 + (r - i) / 3 + (b - i) / 3;
    ans = max(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}
