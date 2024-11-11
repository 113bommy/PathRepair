#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int g(int a) {
  int res = 1, bound = int(sqrt(a)) + 1, i = 2;
  while (i <= bound && a > 1) {
    if (a % i == 0) {
      int cnt = 1;
      while (a % i == 0) a /= i, ++cnt;
      res *= cnt;
    }
    ++i;
  }
  if (a == 1)
    return res;
  else
    return 2;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    int a = g(A), b = g(B), c = g(C), ab = g(gcd(A, B)), bc = g(gcd(B, C)),
        ca = g(gcd(C, A)), abc = g(gcd(gcd(A, B), C));
    int ans = a * b * c - ab * bc * ca + abc * (ab * bc + bc * ca + ca * ab) -
              a * bc * (bc - 1) / 2 - b * ca * (ca - 1) / 2 -
              c * ab * (ab - 1) / 2 - abc * (abc + 1) * (ab + bc + ca) / 2 +
              abc * (abc + 1) * (abc + 2) / 6;
    printf("%d\n", ans);
  }
  return 0;
}
