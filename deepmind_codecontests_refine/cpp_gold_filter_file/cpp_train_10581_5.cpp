#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  double x = 10000, a, b;
  scanf("%d%d", &n, &m);
  while (n--) {
    cin >> a >> b;
    x = min(x, a / b);
  }
  printf("%.8f\n", x * m);
  return 0;
}
