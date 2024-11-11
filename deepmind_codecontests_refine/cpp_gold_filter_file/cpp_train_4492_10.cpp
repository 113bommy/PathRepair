#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  while (~scanf("%I64d %I64d %I64d", &n, &x, &y)) {
    if (y < n)
      printf("-1\n");
    else {
      long long temp = (y - n + 1) * (y - n + 1) + n - 1;
      if (temp < x)
        printf("-1\n");
      else {
        printf("%I64d\n", y - n + 1);
        for (int i = 0; i < n - 1; i++) printf("%d\n", 1);
      }
    }
  }
}
