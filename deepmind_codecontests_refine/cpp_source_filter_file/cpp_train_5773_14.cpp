#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 and m == 2) {
    cout << "0\n1 1\n1 2\n1 1\n";
  } else if (n == 2 and m == 1) {
    cout << "0\n1 1\n2 1\n1 1\n";
  } else if (n == 1) {
    cout << 1 << "\n";
    cout << 1 << " " << m << " " << 1 << " " << 1 << "\n";
    for (int i = 1; i <= m; i++) {
      cout << 1 << " " << i << "\n";
    }
    cout << 1 << " " << 1 << "\n";
  } else if (m == 1) {
    cout << 1 << "\n";
    cout << n << " " << 1 << " " << 1 << " " << 1 << "\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " " << i << "\n";
    }
    cout << 1 << " " << 1 << "\n";
  } else {
    if (n % 2 == 0) {
      cout << 0 << "\n";
      for (int i = 1; i <= n; i++) {
        cout << i << " " << 1 << "\n";
      }
      for (int i = 2; i <= m; i++) {
        cout << n << " " << i << "\n";
      }
      for (int i = n - 1; i >= 1; i--) {
        if (i % 2) {
          for (int j = m; j > 1; j--) {
            cout << i << " " << j << "\n";
          }
        } else {
          for (int j = 2; j <= m; j++) {
            cout << i << " " << j << "\n";
          }
        }
      }
      cout << 1 << " " << 1 << "\n";
    } else if (m % 2 == 0) {
      cout << 0 << "\n";
      for (int i = 1; i <= m; i++) {
        cout << 1 << " " << i << "\n";
      }
      for (int i = 2; i <= n; i++) {
        cout << i << " " << m << "\n";
      }
      for (int i = m - 1; i >= 1; i--) {
        if (i % 2) {
          for (int j = n; j > 1; j--) {
            cout << j << " " << i << "\n";
          }
        } else {
          for (int j = 2; j <= n; j++) {
            cout << j << " " << i << "\n";
          }
        }
      }
      cout << 1 << " " << 1 << "\n";
    } else {
      cout << 1 << "\n";
      cout << n << " " << m << " " << 1 << " " << 1 << "\n";
      for (int i = 1; i <= n; i++) {
        if (i % 2) {
          for (int j = 1; j <= m; j++) {
            cout << i << " " << j << "\n";
          }
        } else {
          for (int j = m; j >= 1; j--) {
            cout << i << " " << j << "\n";
          }
        }
      }
      cout << 1 << " " << 1 << "\n";
    }
  }
  return 0;
}
