#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a < b) {
    printf("-1\n");
    return 0;
  }
  double n = (double)a / b;
  int ni = (int)n;
  int l = ni;
  if (l % 2 == 0) l -= 1;
  int diff = a - l * b;
  double res = b + (double)diff / (ni + (ni % 2));
  printf("%.9f\n", res);
  return 0;
}
