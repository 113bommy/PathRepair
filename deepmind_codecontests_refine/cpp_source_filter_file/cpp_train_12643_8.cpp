#include <bits/stdc++.h>
using namespace std;
const long mod = 1000000007;
int main() {
  long x, y, n;
  cin >> x >> y >> n;
  long arr[6] = {x, y, y - x, -x, -y, x - y};
  cout << (mod + arr[n - 1 % 6] % mod) % mod;
}
