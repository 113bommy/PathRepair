#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c1 = 9, sum = 0, sum2 = 0, t = 1;
  cin >> n;
  while (n > 0) {
    sum = n - c1;
    if (sum < 0)
      sum = n;
    else if (sum > 0)
      sum = c1;
    n -= c1;
    sum *= t;
    sum2 += sum;
    t++;
    c1 *= 10;
  }
  cout << sum2;
  return 0;
}
