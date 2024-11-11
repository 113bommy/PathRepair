#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
long long n, m;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) % m * power(x, y / 2) % m;
  else
    return x * power(x, y / 2) % m * power(x, y / 2) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  cout << (power(3, n) - 1) % m << "\n";
  return 0;
}
