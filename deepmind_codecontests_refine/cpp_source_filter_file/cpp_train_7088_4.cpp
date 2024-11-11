#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int g = k;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    g = gcd(k, x);
  }
  printf("%d\n", k / g);
  for (int i = 0; i < k / g; i++) printf("%d ", i * g);
  printf("\n");
  return 0;
}
