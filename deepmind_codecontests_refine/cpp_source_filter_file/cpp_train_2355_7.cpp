#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int M = 17;
void solve() {
  int n, x;
  cin >> n >> x;
  if (n % 4 == 0) {
    cout << "YES" << endl;
    cout << x << " " << x + (1 << M) << " ";
    bool found = false;
    for (int i = 1; i <= n / 2 - 1; i++) {
      if (x == i) {
        found = true;
      } else {
        cout << i << " " << i + (1 << M) << " ";
      }
    }
    if (found) {
      cout << n / 2 << " " << n / 2 + (1 << M) << " ";
    }
  } else if (n % 4 == 1) {
    cout << "YES" << endl;
    cout << x << " ";
    bool found = false;
    for (int i = 1; i <= n / 2; i++) {
      if (i == x) {
        found = true;
      } else {
        cout << i << " " << i + (1 << M) << " ";
      }
    }
    if (found) {
      cout << n / 2 + 1 << " " << n / 2 + 1 + (1 << M) << " ";
    }
  } else if (n % 4 == 2) {
    if (x == 0) {
      if (n == 2) {
        cout << "NO" << endl;
        return;
      } else {
        cout << "YES" << endl;
        cout << 0 + (1 << M) << " ";
        int cur_xor = 0;
        for (int i = 1; i <= n - 3; i++) {
          cout << i << " ";
          cur_xor ^= i;
        }
        cur_xor ^= n - 2;
        if (cur_xor != 0) {
          cout << n - 2 << " ";
        } else {
          cur_xor ^= n - 2;
          cur_xor ^= n - 1;
          cout << n - 1 << " ";
        }
        cout << cur_xor + (1 << M) << " ";
      }
    } else {
      cout << "YES" << endl;
      cout << 0 << " " << x << " ";
      bool found = false;
      for (int i = 1; i <= n / 2 - 1; i++) {
        if (i == x) {
          found = true;
        } else {
          cout << i << " " << i + (1 << M) << " ";
        }
      }
      if (found) {
        cout << n / 2 << " " << n / 2 + (1 << M) << " ";
      }
    }
  } else {
    cout << "YES" << endl;
    cout << x + (1 << M) << " ";
    bool found = false;
    for (int i = 1; i <= n / 2; i++) {
      if (i == x) {
        found = true;
      } else {
        cout << i << " " << i + (1 << M) << " ";
      }
    }
    if (found) {
      cout << n / 2 + 1 << " " << n / 2 + 1 + (1 << M) << " ";
    }
  }
  cout << endl;
}
int main() {
  srand(time(NULL));
  solve();
  return 0;
}
