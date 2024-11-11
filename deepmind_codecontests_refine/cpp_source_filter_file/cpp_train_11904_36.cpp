#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  if (a + b + c == 0)
    printf("2.0 0.0 0.0\n");
  else
    printf("%.10lf %.10lf %.10lf\n", n * 1.0 * a / (a + b + c),
           n * 1.0 * b / (a + b + c), n * 1.0 * c / (a + b + c));
  return 0;
}
