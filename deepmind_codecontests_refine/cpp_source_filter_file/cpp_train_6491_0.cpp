#include <bits/stdc++.h>
using namespace std;
long long p, d;
int main() {
  cin >> p >> d;
  long long low = p - d;
  long long next;
  long long curfac = 10;
  while (1) {
    long long n = (p % curfac) + 1;
    if (n == curfac) n = 0;
    if (p - n > low)
      p -= n;
    else
      break;
    curfac *= 10;
  }
  cout << p << endl;
  return 0;
}
