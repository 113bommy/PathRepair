#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, a, b, c;
  scanf("%d%d%d%d", &s, &a, &b, &c);
  if (a + b + c == 0) {
    printf("%d", s);
    puts(".0 0.0 0.0");
  } else {
    printf("%.20lf %.20lf %.20lf", s / (a + b + c + 0.0) * a,
           s / (a + b + c + 0.0) * b, s / (a + b + c + 0.0) * c);
    puts("");
  }
  return 0;
}
