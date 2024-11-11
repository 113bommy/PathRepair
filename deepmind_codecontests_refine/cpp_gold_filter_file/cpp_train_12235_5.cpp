#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e4 + 1;
const long long k = sqrt(1e9) + 1;
long long n;
long long GTN(long long x, long long y) {
  if (y == 0) {
    return 1;
  } else {
    long long tmp = GTN(x, y / 2);
    if (y % 2 == 0) {
      return tmp * tmp;
    } else {
      return tmp * tmp * x;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cout << 2 * 4 * 3 * GTN(4, n - 3) + 4 * (n - 3) * 9 * GTN(4, n - 4);
}
