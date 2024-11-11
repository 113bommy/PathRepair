#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int i, n, k;
  string st;
  cin >> n >> k >> st;
  if (k - 1 < n - k) {
    for (k; k > 1; k--)
      cout << "LEFT"
           << "\n";
    for (k; k <= n; k++) {
      cout << "WRITE " << st[k - 1] << "\n";
      if (k != n)
        cout << "RIGHT"
             << "\n";
    }
  } else {
    for (k; k < n; k++)
      cout << "RIGHT"
           << "\n";
    for (k; k >= 1; k--) {
      cout << "WRITE " << st[k - 1] << "\n";
      if (k != 1)
        cout << "LEFT"
             << "\n";
    }
  }
}
