#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt + 1; i++) {
      for (int j = 0; j < i; j++) {
        cout << '(';
      }
      for (int j = 0; j < i; j++) {
        cout << ')';
      }
      for (int j = 0; j < tt - i; j++) {
        cout << "()";
      }
      cout << endl;
    }
  }
}
