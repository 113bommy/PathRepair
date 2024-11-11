#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int main() {
  long long n, k, p;
  cin >> n >> k >> p;
  long long e = n - k;
  for (int i = 0; i < (p); i++) {
    long long x;
    cin >> x;
    x--;
    if (k == 0) {
      cout << '.';
      continue;
    }
    if (k == n) {
      cout << 'X';
      continue;
    }
    if (k == 1) {
      if (x == n - 1)
        cout << 'X';
      else
        cout << '.';
      continue;
    }
    if (k > n / 2) {
      if (x < 2 * e && x % 2 == 0)
        cout << '.';
      else
        cout << 'X';
    } else {
      long long ee = n - k - k + 1;
      int f = ee % 2;
      long long xx = n - 1 - x;
      if (f == 0) {
        if (xx < 2)
          cout << 'X';
        else if (xx < 2 * k - 2) {
          if (xx % 2)
            cout << 'X';
          else
            cout << '.';
        } else
          cout << '.';
      } else {
        if (xx < 2 * k) {
          if (xx % 2)
            cout << '.';
          else
            cout << 'X';
        } else
          cout << '.';
      }
    }
  }
  cout << endl;
  return 0;
}
