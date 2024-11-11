#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline void solve() {
  int n;
  cin >> n;
  char A[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  bool top = false;
  bool bottom = false;
  if (A[1][0] == A[0][1]) {
    top = true;
  }
  if (A[n - 1][n - 2] == A[n - 2][n - 1]) {
    bottom = true;
  }
  if (top && bottom) {
    if (A[1][0] != A[n - 1][n - 2])
      cout << 0 << "\n";
    else {
      cout << 2 << "\n";
      cout << n << " " << n - 1 << "\n";
      cout << n - 1 << " " << n << "\n";
    }
  } else if (top) {
    cout << 1 << "\n";
    if (A[n - 1][n - 2] == A[1][0]) {
      cout << n << " " << n - 1 << "\n";
    } else {
      cout << n - 1 << " " << n << "\n";
    }
  } else if (bottom) {
    cout << 1 << "\n";
    if (A[n - 1][n - 2] == A[1][0]) {
      cout << 2 << " " << 1 << "\n";
    } else {
      cout << 1 << " " << 2 << "\n";
    }
  } else {
    cout << 2 << "\n";
    cout << 1 << " " << 2 << "\n";
    if (A[n - 1][n - 2] == A[1][0]) {
      cout << n << " " << n - 1 << "\n";
    } else {
      cout << n - 1 << " " << n << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
