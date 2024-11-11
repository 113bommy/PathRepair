#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double R, r;
  scanf("%d%lf%lf", &n, &R, &r);
  if (R < r) {
    printf("NO\n");
  } else if (R < 2 * r && R >= r) {
    if (n < 2) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  } else if (R == 2 * r) {
    if (n <= 2) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  } else {
    double param = r / (R - r);
    int total = 3.14159265 / asin(param);
    if (n > total)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
