#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a, b, c, d;
  scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
  if (n <= 4 || k <= n)
    cout << -1 << endl;
  else
    for (int rep = 1; rep <= 2; rep++) {
      printf("%d %d ", a, c);
      for (int i = 1; i <= n; i++) {
        if (i != a || i != b || i != c || i != d) printf("%d ", i);
      }
      printf("%d %d\n", b, d);
      swap(a, c);
      swap(b, d);
    }
}
