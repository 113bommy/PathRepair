#include <bits/stdc++.h>
using namespace std;
const int maxn = 3300;
int c[maxn];
int n;
void add(int x) {
  while (x <= n) {
    c[x]++;
    x += x & -x;
  }
}
int sum(int x) {
  int res = 0;
  while (x) {
    res += c[x];
    x -= x & -x;
  }
  return res;
}
int main() {
  while (~scanf("%d", &n)) {
    memset(c, 0, sizeof(c));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int p;
      scanf("%d", &p);
      ans += 2 * (p - 1 - sum(p));
      add(p);
    }
    if (ans) ans--;
    printf("%lf\n", (double)ans);
  }
}
