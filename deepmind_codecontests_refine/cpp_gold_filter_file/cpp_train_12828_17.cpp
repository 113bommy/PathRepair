#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long arr[N] = {0};
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b, c, d, n, m;
    cin >> n >> a >> b;
    long long l1 = a + b - 1;
    if (n + 1 > a + b) {
      cout << 1 << " " << a + b - 1 << "\n";
    } else {
      cout << min(a + b - n + 1, n) << " " << n << "\n";
    }
  }
}
