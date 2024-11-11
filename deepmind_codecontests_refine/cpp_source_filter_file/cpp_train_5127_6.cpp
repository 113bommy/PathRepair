#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      cout << n + 2 * k << "\n";
    } else {
      int div = 0;
      int t = n;
      for (int i = 2; i < sqrt(t); i++) {
        if (t % i == 0) {
          div = i;
          break;
        }
      }
      if (div == 0) {
        div = n;
      }
      n += div;
      cout << n + 2 * (k - 1) << "\n";
    }
  }
}
