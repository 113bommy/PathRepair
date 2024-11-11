#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (k <= n - 1) {
    cout << k + 1 << " " << 1;
    return 0;
  }
  k = k - n;
  long long int p = k / (m - 1);
  if (p % 2 == 1) {
    cout << n - p << " " << m - k % (m - 1);
  } else
    cout << n - p << " " << k % (m - 1) + 2;
}
