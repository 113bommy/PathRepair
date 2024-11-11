#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n;
  for (cin >> q; q > 0; q--) {
    cin >> n;
    for (int i = (int)(0); i < (int)(n); i++) {
      for (int j = (int)(0); j < (int)(i + 1); j++) {
        cout << '(';
      }
      for (int j = (int)(0); j < (int)(i + 1); j++) {
        cout << ')';
      }
      for (int j = (int)(i + 1); j < (int)(n); j++) {
        cout << '(';
      }
      for (int j = (int)(i + 1); j < (int)(n); j++) {
        cout << ')';
      }
      cout << endl;
    }
  }
  return 0;
}
