#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1;
  while (n > 0) {
    res = (res * res) % temp;
    if (n & 1) res = (res * a) % temp;
    n /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0)
    return (b);
  else
    return (gcd(b % a, a));
}
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n + 1)) / 2 > k) {
    int x = 0, y = 0, tot = 0;
    while (1) {
      tot++;
      cout << x << " " << y << endl;
      y++;
      if (tot == n) break;
    }
  } else {
    cout << "no solution";
  }
  return 0;
}
