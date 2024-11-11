#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  scanf("%d:%d", &x, &y);
  x %= 12;
  printf("%.10lf %d\n", x * 30 + y * 0.5, y * 6);
  return 0;
}
