#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a;
  cin >> n;
  long long i, j;
  for (long long k = 0; k < n; k++) {
    cin >> a;
    if (a == 1) i = k + 1;
    if (a == n) j = k + 1;
  }
  if ((i == 1 and j == n) or (i != 1 and j == n) or (i == 1 and j != n) or
      (j == 1 and i == n) or (i != n and j == 1) or (i == n and j != 1))
    return cout << n - 1, 0;
  long long z = max(abs(1 - j), abs(5 - j));
  long long x = max(abs(i - 1), abs(i - 5));
  cout << max(z, x);
  return 0;
}
