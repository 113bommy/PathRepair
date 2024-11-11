#include <bits/stdc++.h>
using namespace std;
int n, k;
int pre[int(2e5) + 10], num[(int(2e5)) + 10];
int main() {
  istream& in = cin;
  in >> n >> k;
  int p = n - 1 - k;
  if (p == 0) {
    cout << 2 << endl;
    for (int i = 2; i <= n; ++i) cout << 1 << " " << i << endl;
  } else {
    if (p == 1) {
      cout << 3 << endl;
      cout << 1 << " " << 2 << endl;
      for (int i = 3; i <= n; ++i) {
        if (i % 2 == 0) {
          cout << 1 << " " << i << endl;
        } else {
          cout << 2 << " " << i << endl;
        }
      }
    } else {
      if (p <= k) {
        cout << 4 << endl;
        for (int i = 2; i < 2 + p; ++i) {
          cout << 1 << " " << i << endl;
        }
        for (int i = 1; i <= p; ++i) {
          cout << i + 1 << " " << 1 + p + i << endl;
        }
        for (int i = 2 + p + p; i <= n; ++i) cout << 1 << " " << i << endl;
      } else {
        int x = p / k;
        int y = p % k;
        if (y == 0) {
          cout << 2 * x + 2 << endl;
        } else if (y == 1) {
          cout << x + x + 3 << endl;
        } else {
          cout << x + x + 4 << endl;
        }
        for (int i = 1; i <= k; ++i) {
          pre[i] = n;
        }
        for (int i = n - 1; i > k; --i) {
          int d = (i % k) + 1;
          cout << i << " " << pre[d] << endl;
          pre[d] = i;
        }
        for (int i = 1; i <= k; ++i) cout << i << " " << pre[k] << endl;
      }
    }
  }
  return 0;
}
