#include <bits/stdc++.h>
using namespace std;
int a[2000010], b[2000010];
int bmax(int x, int y) { return x ^ ((x ^ y) & -(x < y)); }
int main() {
  int i, j, n, t;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &t);
    a[t] = t;
  }
  for (i = 1; i <= 2000000; i++) b[i] = bmax(a[i], b[i - 1]);
  int x = 0;
  for (i = 1; i <= 1000000; i++) {
    if (a[i]) {
      for (j = 2 * i; j <= 2000000; j += i) x = bmax(x, b[j - 1] % i);
    }
  }
  cout << x << endl;
  return 0;
}
