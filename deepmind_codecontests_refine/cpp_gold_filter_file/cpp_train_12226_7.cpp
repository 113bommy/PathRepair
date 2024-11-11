#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  if (k <= (n - 1 >> 1)) {
    cout << n * k << endl;
    int c;
    for (int i = 1; i <= k; ++i)
      for (int j = 1; j <= n; ++j) {
        c = j + i;
        cout << j << " " << (c > n ? c - n : c) << endl;
      }
  } else {
    cout << -1 << endl;
  }
}
