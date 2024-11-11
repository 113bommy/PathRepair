#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, y, i;
  cin >> n >> m >> k;
  if (k < n)
    cout << k + 1 << " " << 1;
  else {
    k = k - n;
    if ((k / (m - 1)) % 2 == 0)
      cout << n - k / (m - 1) << " " << 2 + k % (m - 1);
    else
      cout << n - k / (m - 1) << " " << m - k % (m - 1);
  }
  return 0;
}
