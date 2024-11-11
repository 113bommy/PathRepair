#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d:%d", &a, &b);
  if (a == 12) a = 0;
  printf("%.6lf %d", (a + b / 60.0) * (360 / 12), b * 6);
  return 0;
}
