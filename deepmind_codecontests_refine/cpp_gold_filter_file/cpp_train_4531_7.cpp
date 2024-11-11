#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
int main(int argc, char** argv) {
  long long n, t = 0;
  long long i = 0;
  cin >> n;
  if (n == 0) {
    cout << "0 0";
    return 0;
  }
  long long m = floor(sqrt(n / 3));
  for (i = m; 3 * i * (i + 1) >= n; i--)
    ;
  long long c = i;
  n -= 3 * i * (i + 1);
  long long x = 2 * c + 2, y = 0;
  if (n <= i + 1) {
    x -= n, y += 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x -= i + 1, y += 2 * (i + 1);
  n -= i + 1;
  if (n <= i + 1) {
    x -= 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x -= 2 * (i + 1);
  n -= i + 1;
  if (n <= i + 1) {
    x -= n, y -= 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x -= i + 1, y -= 2 * (i + 1);
  n -= i + 1;
  if (n <= i + 1) {
    x += n, y -= 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x += i + 1, y -= 2 * (i + 1);
  n -= i + 1;
  if (n <= i + 1) {
    x += 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x += 2 * (i + 1);
  n -= i + 1;
  if (n <= i + 1) {
    x += n, y += 2 * n;
    cout << x << " " << y;
    return 0;
  }
  x += i + 1, y += 2 * (i + 1);
  n -= i + 1;
  return 0;
}
