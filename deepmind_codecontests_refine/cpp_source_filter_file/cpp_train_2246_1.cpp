#include <bits/stdc++.h>
using namespace std;
int a, b, sum, sum1, sumlast1, sumlast2, c = 1;
int main() {
  cin >> a >> b;
  sumlast1 = a + b;
  while (a > 0) {
    if (a % 10 != 0) {
      sum += a % 10 * c;
      c *= 10;
    }
    a /= 10;
  }
  c = 1;
  while (b > 0) {
    if (b % 10 != 0) {
      sum1 += b % 10 * c;
      c = c * 10;
    }
    b /= 10;
  }
  c = 1;
  while (sumlast1 > 0) {
    if (sumlast1 != 0) {
      sumlast2 += sumlast1 % 10 * c;
      c = c * 10;
    }
    sumlast1 /= 10;
  }
  if (sumlast2 == sum + sum1)
    cout << "YES";
  else
    cout << "NO";
}
