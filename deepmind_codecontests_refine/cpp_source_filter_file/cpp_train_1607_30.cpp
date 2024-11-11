#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else {
    long long int p = power(x, y / 2);
    if (y % 2 == 0)
      return (p * p) % 1000000007LL;
    else
      return (x * ((p * p) % 1000000007LL)) % 1000000007LL;
  }
}
long long int gcd(long long int x, long long int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  if (x + y + z == 0) {
    if (a + b + c == 3)
      cout << "NO";
    else
      cout << "YES";
  } else if (x + y + z == 1) {
    if (x == 1) {
      if ((a == 0 && a + b + c == 2))
        cout << "NO";
      else
        cout << "YES";
    } else if (y == 1) {
      if ((b == 0 && a + b + c == 2))
        cout << "NO";
      else
        cout << "YES";
    } else if (z == 1) {
      if ((c == 0 && a + b + c == 2))
        cout << "NO";
      else
        cout << "YES";
    }
  } else if (x + y + z == 2) {
    if (x == 0) {
      if (a == 1 && a + b + c == 1)
        cout << "NO";
      else
        cout << "YES";
    } else if (y == 0) {
      if (b == 1 && a + b + c == 1)
        cout << "NO";
      else
        cout << "YES";
    } else if (z == 0) {
      if (c == 1 && a + b + c == 1)
        cout << "NO";
      else
        cout << "YES";
    }
  } else {
    if (x + y + z == 0)
      cout << "NO";
    else
      cout << "YES";
  }
}
