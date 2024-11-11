#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k != n && k != 1) {
    if (n - k >= k)
      cout << 3 * n + k - 1;
    else {
      cout << 3 * n + n - k;
    }
  } else
    cout << 3 * n;
  return 0;
}
