#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (i <= n - k)
      s += a;
    else
      s += x;
  }
  printf("%d ", s);
  return 0;
}
