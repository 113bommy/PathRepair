#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  if (n != 2 * k + 1) {
    cout << "-1\n";
    return 0;
  }
  cout << k * n << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int nxt = (i + j + 1) % n;
      cout << (i + 1) << " " << (nxt + 1) << "\n";
    }
  }
}
