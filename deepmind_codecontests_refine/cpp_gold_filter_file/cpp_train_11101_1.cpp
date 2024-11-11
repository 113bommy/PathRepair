#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n;
struct poly {
  int deg;
  int a[155];
  poly() { memset(a, 0, sizeof(a)); }
  void mul_x() {
    deg++;
    for (int i = deg; i >= 1; i--) a[i] = a[i - 1];
    a[0] = 0;
  }
  void nega() {
    for (int i = 0; i <= deg; i++) a[i] = -a[i];
  }
  void output() {
    printf("%d\n%d", deg, a[0]);
    for (int i = 1; i <= deg; i++) printf(" %d", a[i]);
    printf("\n");
  }
} B, AmodB;
poly operator+(poly a, poly b) {
  int mx = max(a.deg, b.deg);
  poly ret;
  ret.deg = mx;
  for (int i = 0; i <= mx; i++) ret.a[i] = a.a[i] + b.a[i];
  return ret;
}
int main() {
  scanf("%d", &n);
  AmodB.deg = 0;
  AmodB.a[0] = 0;
  B.deg = 0;
  B.a[0] = 1;
  for (int i = 1; i <= n; i++) {
    poly tmp = B;
    B.mul_x();
    for (int i = 0; i <= AmodB.deg; i++)
      if (B.a[i] == AmodB.a[i] && B.a[i]) {
        AmodB.nega();
        break;
      }
    B = B + AmodB;
    AmodB = tmp;
  }
  B.output();
  AmodB.output();
}
