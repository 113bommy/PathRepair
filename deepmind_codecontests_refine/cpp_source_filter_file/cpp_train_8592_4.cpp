#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, m, n, l, tn;
int ans;
int main() {
  cin >> tn;
  while (tn--) {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
      cin >> i;
      m = (m - (i - 1) + n) % n;
    }
    cout << m % n + 1 << endl;
  }
  return 0;
}
