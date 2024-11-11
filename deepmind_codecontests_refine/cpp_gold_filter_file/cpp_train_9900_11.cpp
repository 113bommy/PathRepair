#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  if (k > 2 * n - 1 || k == 1 || k == 2) {
    cout << 0;
  } else if (n >= k) {
    cout << (k - 1) / 2;
  } else if (n < k) {
    cout << 1 + (2 * n - 1 - k) / 2;
  }
  return 0;
}
