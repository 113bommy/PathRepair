#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  int ans;
  int x;
  if (n & 1)
    x = n / 2 + 1;
  else
    x = n / 2 + 1;
  for (int i = x; i <= n; i--) {
    int y = n - i;
    if (gcd(i, y) == 1) {
      printf("%d %d", y, i);
      return 0;
    }
  }
}
