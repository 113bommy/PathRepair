#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int g(int x) {
  int n = int(sqrt(x)), res = 0;
  for (int i = 1; i <= n + 1; ++i)
    if (!(x % i)) res += i * i == x ? 1 : 2;
  return res;
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
