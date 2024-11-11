#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e[3], m = 0;
  e[m++] = a;
  e[m++] = c;
  e[m++] = d;
  sort(e, e + 3);
  int sum = e[0] * 256;
  a -= e[0];
  if (a > 0 && a > b) {
    sum += b * 32;
  } else if (a > 0 && b > a) {
    sum += a * 32;
  }
  cout << sum;
  return 0;
}
