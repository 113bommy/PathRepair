#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, c = 0, ans = 0, i = 0;
  cin >> n;
  x = n;
  while (x > 0) {
    x /= 10;
    c++;
  }
  if (c == 1) {
    cout << n;
    return 0;
  }
  c--;
  x = 1;
  while (c > 0) {
    ans += (9 * x * (i + 1));
    i++;
    x *= 10;
    c--;
  }
  x = 1;
  for (c = 0; c < i; c++) {
    x *= 10;
  }
  x = n - x;
  ans += ((x + 1) * (i + 1));
  cout << ans;
  return 0;
}
