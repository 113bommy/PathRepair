#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  if (n == 1) {
    if (k == 0) {
      cout << 1 << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else if (k < n / 2) {
    cout << -1 << "\n";
  } else {
    long long int d = k - ((n - 2) / 2);
    cout << d << " " << 2 * d << " ";
    for (long long int i = 3; i <= n; i++) {
      cout << 2 * d + i << " ";
    }
    cout << "\n";
  }
}
