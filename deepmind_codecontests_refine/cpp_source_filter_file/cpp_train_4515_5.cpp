#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
long long fast_power(long long x, long long n, long mood) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return fast_power(x * x, n / 2, mood);
  else
    return (x * fast_power((x * x) % mood, (n - 1) / 2, mood));
}
int d[1000000];
int main() {
  int n;
  cin >> n;
  if (n < 3)
    cout << n << endl;
  else if (n % 2 == 1)
    cout << n * (n - 1) * (n - 2);
  else if (n % 6 == 0)
    cout << (n - 1) * (n - 2) * (n - 3);
  else
    cout << n * (n - 1) * (n - 3);
  return 0;
}
