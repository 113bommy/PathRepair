#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  float x, y, s;
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%f%f", &x, &y);
    s += y;
  }
  printf("%.3f", s / n + 5);
  return 0;
}
