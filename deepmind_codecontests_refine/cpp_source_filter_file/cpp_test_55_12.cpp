#include <bits/stdc++.h>
using namespace std;
long long int pwr(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res % 1000000007 * a % 1000000007) % 1000000007;
    }
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  long long int k, ans = 1, nodes = 0;
  cin >> k;
  nodes = pwr(2, k);
  nodes = nodes - 2;
  ans = pwr(4, nodes);
  ans %= 1000000007;
  ans *= 6;
  cout << (ans % 1000000007);
  return 0;
}
