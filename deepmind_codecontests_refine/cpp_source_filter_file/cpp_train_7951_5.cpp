#include <bits/stdc++.h>
using namespace std;
int a, b, n, sum = 0;
double o;
int main() {
  cin >> n;
  for (a = 3; a <= n; a++)
    for (b = a + 1; b <= n; b++) {
      o = sqrt(a * a + b * b);
      if (o * o == a * a + b * b && o <= n) sum++;
    }
  cout << sum;
  return 0;
}
