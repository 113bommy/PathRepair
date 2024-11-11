#include <bits/stdc++.h>
using namespace std;
int a, b, m, x, f[100001], cnt = 1;
int main() {
  scanf("%d%d%d%d", &a, &b, &m, &x);
  while (1) {
    x = (a * x + b) % m;
    if (f[x] != 0) {
      printf("%d", cnt - f[x]);
      return 0;
    }
    f[x] = cnt;
    cnt++;
  }
}
