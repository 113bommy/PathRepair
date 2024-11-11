#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int a[110], b[110];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int v = ((n + 1 < m + 1) ? (m + 1) : (n + 1));
  int zn1 = 1, zn2 = 1;
  for (int i = (0); i < (n + 1); ++i) {
    scanf("%d", &a[i + v - n - 1]);
    if (i == 0)
      zn1 = a[i + v - n - 1] /
            ((a[i + v - n - 1] > 0) ? a[i + v - n - 1] : -(a[i + v - n - 1]));
  }
  for (int i = (0); i < (m + 1); ++i) {
    scanf("%d", &b[i + v - m - 1]);
    if (i == 0)
      zn2 = a[i + v - n - 1] /
            ((a[i + v - n - 1] > 0) ? a[i + v - n - 1] : -(a[i + v - n - 1]));
  }
  if (b[0] == 0) {
    if (zn1 * zn2 > 0)
      printf("Infinity\n");
    else
      printf("-Infinity\n");
  } else {
    int g = gcd(((a[0] > 0) ? a[0] : -(a[0])), ((b[0] > 0) ? b[0] : -(b[0])));
    a[0] /= g;
    b[0] /= g;
    if (b[0] < 0) {
      a[0] = -a[0];
      b[0] = -b[0];
    }
    printf("%d/%d\n", a[0], b[0]);
  }
  return 0;
}
