#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int sum = 0;
  int a, b, c, d;
  int minn = 0;
  cin >> a >> b >> c >> d;
  if (a <= c && a <= d) {
    minn = a;
  } else if (c <= a && c <= d) {
    minn = c;
  } else {
    minn = d;
  }
  sum += 256 * minn;
  a -= minn;
  c -= minn;
  d -= minn;
  if (a <= b && a != 0 && b != 0) {
    sum += 32 * a;
  } else if (a >= b && a != 0 && b != 0) {
    sum += 32 * b;
  }
  cout << sum;
  return 0;
}
