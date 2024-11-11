#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, q, i, j, k;
  cin >> n >> k >> q;
  if (n % 2 == 0) {
    if (k > n / 2) {
      long long int y = 2ll * (n * 1ll - k * 1ll);
      while (q--) {
        long long int x;
        cin >> x;
        if (x > y) {
          cout << "X";
        } else {
          if (x % 2 == 1) {
            cout << ".";
          } else {
            cout << "X";
          }
        }
      }
    } else {
      long long int y = n * 1ll - 2ll * k;
      while (q--) {
        long long int x;
        cin >> x;
        if (x <= y) {
          cout << ".";
        } else {
          if (x % 2) {
            cout << ".";
          } else {
            cout << "X";
          }
        }
      }
    }
  } else {
    if (!k) {
      while (q--) {
        long long int x;
        cin >> x;
        cout << ".";
      }
    } else if (k <= n / 2) {
      long long int y = n - 1ll - 2ll * (k - 1ll);
      while (q--) {
        long long int x;
        cin >> x;
        if (x == n) {
          cout << "X";
        } else if (x <= y) {
          cout << ".";
        } else {
          cout << ((x - y) % 2 == 1 ? "." : "X");
        }
      }
    } else {
      while (q--) {
        long long int x;
        cin >> x;
        if (x <= 2ll * (n - k)) {
          cout << ((x % 2 == 1) ? "." : "X");
        } else {
          cout << "X";
        }
      }
    }
  }
  cout << "\n";
}
