#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  long long a[10000];
  int p;
  cin >> n >> k >> p;
  for (int i = 0; i < p; i++) {
    cin >> a[i];
  }
  if (!k) {
    for (int i = 0; i < p; i++) cout << '.';
  } else if (k == 1) {
    for (int i = 0; i < p; i++)
      if (a[i] == n)
        cout << 'X';
      else
        cout << '.';
  } else if (n <= 2ll * k) {
    for (int i = 0; i < p; i++) {
      if (a[i] <= 2ll * n - 2ll * k) {
        if (a[i] % 2ll)
          cout << '.';
        else
          cout << 'X';
      } else
        cout << 'X';
    }
  } else {
    if (n % 2) {
      for (int i = 0; i < p; i++) {
        if (a[i] <= (n - 2ll * (k - 1ll)))
          cout << '.';
        else if (a[i] == n)
          cout << 'X';
        else {
          a[i] -= (n - 2ll * (k - 1ll));
          if (a[i] % 2ll)
            cout << 'X';
          else
            cout << '.';
        }
      }
    } else {
      for (int i = 0; i < p; i++) {
        a[i] -= 2ll * k;
        if (a[i] <= 0)
          cout << '.';
        else if (a[i] % 2ll)
          cout << '.';
        else
          cout << 'X';
      }
    }
  }
  cout << endl;
  return 0;
}
