#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << 1 << endl << 1 << ' ' << 1;
    return 0;
  }
  if (n == 2) {
    cout << 1 << endl << 1 << ' ' << 1;
    return 0;
  }
  if (n % 2 == 0) {
    if (n % 4 == 0) {
      cout << 0 << endl << n / 2 << ' ';
      for (int i = 1; i < n / 2; i += 2) {
        cout << i << ' ';
      }
      for (int i = n / 2 + 2; i <= n; i += 2) {
        cout << i << ' ';
      }
    } else {
      cout << 1 << endl << n / 2 << ' ';
      int q = n - 2;
      for (int i = 1; i < q / 2; i += 2) {
        cout << i << ' ';
      }
      for (int i = q / 2 + 2; i <= q; i += 2) {
        cout << i << ' ';
      }
      cout << n - 1;
    }
  } else {
    if ((n + 1) % 4 == 0) {
      cout << 0 << endl << n / 2 + 1 << ' ';
      for (int i = 1; i <= n / 2; i += 2) {
        cout << i << ' ';
      }
      cout << n / 2 + 1 << ' ';
      for (int i = n / 2 + 3; i <= n; i += 2) {
        cout << i << ' ';
      }
    } else {
      cout << 1 << endl << n / 2 + 1 << ' ';
      int q = n - 2;
      for (int i = 1; i <= q / 2; i += 2) {
        cout << i << ' ';
      }
      cout << n / 2 + 1 << ' ';
      for (int i = q / 2 + 3; i <= q; i += 2) {
        cout << i << ' ';
      }
      cout << n - 1;
    }
  }
}
