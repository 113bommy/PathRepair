#include <bits/stdc++.h>
using namespace std;
const int N = 0;
long long k, b, n, t;
int main() {
  cin >> k >> b >> n >> t;
  long long z = k + b;
  int i = n - 1;
  for (; i > -1; i--) {
    if (t < z) break;
    z = z * k + b;
  }
  cout << max(i + 1, 0) << endl;
}
