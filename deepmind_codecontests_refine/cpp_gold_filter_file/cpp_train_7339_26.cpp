#include <bits/stdc++.h>
using namespace std;
long long fastexp(long long a, long long n, long long nod = LLONG_MAX) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % nod;
    a = (a * a) % nod;
    n >>= 1;
  }
  return ans;
}
void fun() {
  char c[10][10];
  int movesa = 100, movesb = 100;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      if (c[i][j] == '.') continue;
      if (c[i][j] == 'W') {
        bool ok = 0;
        for (int k = 1; k < i; k++) {
          if (c[k][j] != '.') {
            ok = 1;
            break;
          }
        }
        if (ok) continue;
        movesa = min(movesa, i - 1);
      } else {
        bool ok = 0;
        for (int k = i + 1; k < 9; k++) {
          if (c[k][j] != '.') {
            ok = 1;
            break;
          }
        }
        if (ok) continue;
        movesb = min(movesb, 8 - i);
      }
    }
  }
  if (movesa <= movesb) {
    cout << "A";
  } else {
    cout << "B";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(20);
  cout << fixed;
  int t = 1;
  while (t--) {
    fun();
  }
}
