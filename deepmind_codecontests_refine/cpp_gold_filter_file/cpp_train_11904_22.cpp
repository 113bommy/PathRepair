#include <bits/stdc++.h>
using namespace std;
int s, a, b, c;
int main() {
  scanf("%d%d%d%d", &s, &a, &b, &c);
  int total = a + b + c;
  if (total == 0)
    printf("0.0 0.0 0.0\n");
  else
    printf("%.10lf %.10lf %.10lf\n", (double)s * a / total,
           (double)s * b / total, (double)s * c / total);
  return 0;
}
