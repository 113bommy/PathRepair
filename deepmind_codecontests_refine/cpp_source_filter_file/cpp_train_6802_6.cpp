#include <bits/stdc++.h>
using namespace std;
int n;
double a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  if (a + b + c == 0) {
    printf("0 0 0\n");
    return 0;
  }
  printf("%.9lf %.9lf %.9lf\n", (n * a) / (a + b + c), (n * b) / (a + b + c),
         (n * c) / (a + b + c));
  return 0;
}
