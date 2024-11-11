#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, l, v1, v2;
  cin >> d >> l >> v1 >> v2;
  double a;
  a = (l - d) / (double)(v1 + v2);
  printf("%.7f", a);
}
