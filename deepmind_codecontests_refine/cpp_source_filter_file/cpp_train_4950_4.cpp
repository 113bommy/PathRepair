#include <bits/stdc++.h>
using namespace std;
int n, k, tmp = 1;
int c[1000100];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    x = gcd(x, k);
    tmp = (long long)(tmp * x) / gcd(tmp, x);
  }
  if (tmp == k)
    printf("Yes");
  else
    printf("No");
  return 0;
}
