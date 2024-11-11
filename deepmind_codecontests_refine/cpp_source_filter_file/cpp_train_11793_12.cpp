#include <bits/stdc++.h>
using namespace std;
int main() {
  float n, R, r;
  cin >> n >> R >> r;
  if (2 * r == R) {
    if (n <= 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
  if (2 * r > R && r <= R) {
    if (n <= 1)
      printf("YES\n");
    else
      printf("NO\n");
  } else {
    float theta = asin(r / (R - r)) * 180 / M_PI;
    float ch = (theta * n * 2);
    if (ch <= 360.0000000)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
