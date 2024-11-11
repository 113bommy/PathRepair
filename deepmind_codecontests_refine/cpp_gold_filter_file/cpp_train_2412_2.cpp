#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long MAXN = 1e6;
int main() {
  long long r;
  cin >> r;
  for (long long x = 1; x <= MAXN; x++) {
    if (r - 1 - x * x - x > 0 && (r - 1 - x - x * x) % (2 * x) == 0) {
      cout << x << ' ' << (r - 1 - x - x * x) / (2 * x) << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
