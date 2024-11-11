#include <bits/stdc++.h>
using namespace std;
int n;
double x, p, a;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a += 2 * (p = (p + 1) * x) - x;
  }
  printf("%.15f", a);
  return 0;
}
