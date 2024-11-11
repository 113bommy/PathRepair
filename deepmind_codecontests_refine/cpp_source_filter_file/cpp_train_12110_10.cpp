#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ans = 0;
  cin >> a >> b;
  string x[a];
  for (int i = 0; i < a; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < a; i++) {
    bool wasgreat = false;
    for (int j = 0; j < b; j++) {
      bool isgreat = true;
      for (int k = 0; k < a; k++) {
        if (x[i][j] > x[k][j]) {
          isgreat = false;
        }
      }
      if (isgreat) {
        wasgreat = true;
      }
    }
    if (wasgreat) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
