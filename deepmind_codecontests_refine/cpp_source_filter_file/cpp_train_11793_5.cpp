#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, R;
  int n;
  while (cin >> n >> R >> r) {
    if (r > R) {
      printf("NO\n");
      continue;
    }
    if (2 * r > R) {
      if (n <= 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
      continue;
    }
    double angle = asin(r * 1. / (R - r));
    int total = floor((acos(-1)) / angle);
    if (n <= total)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
