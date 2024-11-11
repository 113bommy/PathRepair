#include <bits/stdc++.h>
using namespace std;
int mark[2];
int main() {
  long long int a, b;
  int c;
  scanf("%lld%lld%d", &a, &b, &c);
  int i = 0;
  while (1) {
    i++;
    a = a * 10;
    if (a > 100000000000000000 || i > 1000000) break;
    long long x = (1.0 * a) / b;
    x = x % 10;
    a = a - (x * b);
    if (x == c) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
