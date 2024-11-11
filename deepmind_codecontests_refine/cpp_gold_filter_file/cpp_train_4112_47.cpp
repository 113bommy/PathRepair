#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, k, t, p;
  long long s = 0, sum = 0, j = 1;
  cin >> n;
  p = n;
  while (n > 0) {
    n = n / 10;
    s++;
  }
  for (i = 1; i < s; i++) {
    sum = sum + i * 9 * j;
    j = j * 10;
  }
  j = j - 1;
  cout << sum + ((p - j)) * s << endl;
  return 0;
}
