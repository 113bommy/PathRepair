#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 0x3f3f3f3f;
long long k, b, n, t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> b >> n >> t;
  long long z = 1, op = 0;
  for (int i = 0; i <= n; i++) {
    if (z > t) {
      op = n - i + 1;
      break;
    }
    z = z * k + b;
  }
  cout << op << endl;
  return 0;
}
