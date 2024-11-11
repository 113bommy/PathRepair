#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, j, k, l, m, a = 0, b = 0, c, sum = 0, x = 0, y = 0;
  cin >> n;
  a = n;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  c = sum % 4;
  if (c == 0) {
    cout << a;
    return 0;
  }
  for (i = 1; i <= 100; i++) {
    a = a + 1;
    x = a;
    while (x > 0) {
      y += x % 10;
      x = x / 10;
    }
    if (y % 4 == 0) {
      cout << a;
      return 0;
    }
    y = 0;
  }
  return 0;
}
