#include <bits/stdc++.h>
using namespace std;
const int M = 5000;
const int N = 300000;
const int inf = 1 << 29;
const double eps = 1e-8;
int a[M];
int n;
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 0;
    for (int i = 1; i <= 3000; i++) {
      if (i != a[cnt]) {
        printf("%d\n", i);
        break;
      } else {
        cnt++;
      }
    }
  }
  return 0;
}
