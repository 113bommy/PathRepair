#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    if (n % k == 0)
      cout << n << endl;
    else {
      int tmp = n / k;
      double x = tmp + 0.5;
      cout << (int)(x * k) << endl;
    }
  }
}
