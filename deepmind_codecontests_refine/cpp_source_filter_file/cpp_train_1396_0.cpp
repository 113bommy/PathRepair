#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  long n = 0;
  while (a >= 1 && b >= 1) {
    if (a >= b) {
      n += a / b;
      a = a % b;
    } else {
      n += b / a;
      b = b % a;
    }
  }
  cout << n << endl;
  return 0;
}
