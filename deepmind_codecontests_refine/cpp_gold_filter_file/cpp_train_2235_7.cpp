#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) {
  int ans = 0, i = 1;
  while (b) {
    int tmp = b % 10;
    ans += tmp * i;
    i *= a;
    b /= 10;
  }
  return ans;
}
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
    int tmpa = a, tmpb = b, m = 0;
    while (tmpa) {
      m = max(tmpa % 10, m);
      tmpa /= 10;
    }
    while (tmpb) {
      m = max(tmpb % 10, m);
      tmpb /= 10;
    }
    m++;
    int aa = f(m, a) + f(m, b);
    int ans = 0;
    while (aa) {
      aa /= m;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
