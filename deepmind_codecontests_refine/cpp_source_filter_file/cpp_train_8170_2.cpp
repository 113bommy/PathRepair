#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b;
  cin >> a >> b;
  if (a < b)
    puts("-1");
  else
    printf("%.10f\n", (a + b) / (2. * ((a + b) / (2 * b))));
  return 0;
}
