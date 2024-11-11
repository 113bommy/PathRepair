#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
bool f[MAXN];
int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = MAXN - 1 - x; j >= 0; --j) f[j + x] |= f[j];
  }
  int r = 1, sum = 0, ans = 0;
  while (r < MAXN) {
    int next = -1;
    while (r <= sum + d && r < MAXN) {
      if (f[r]) next = r;
      r++;
    }
    if (next == -1) break;
    sum = next;
    ans++;
  }
  printf("%d %d\n", sum, ans);
  return 0;
}
