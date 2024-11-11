#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000")
using namespace std;
const int MAXN = 110;
int a[MAXN], b[MAXN];
int gcd(int x, int y) {
  if (!y) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  if (n == m) {
    bool flag = false;
    if (a[0] * b[0] < 0) {
      a[0] = abs(a[0]);
      b[0] = abs(b[0]);
      flag = true;
    }
    int g = gcd(a[0], b[0]);
    a[0] /= g;
    b[0] /= g;
    if (flag) {
      printf("-");
    }
    printf("%d/%d\n", a[0], b[0]);
  } else if (n > m) {
    if (a[0] * b[0] < 0) {
      printf("-");
    }
    printf("Infinity\n");
  } else {
    printf("0/1\n");
  }
  return 0;
}
