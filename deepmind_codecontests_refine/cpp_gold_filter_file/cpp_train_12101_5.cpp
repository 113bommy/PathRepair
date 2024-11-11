#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, k;
  while (t--) {
    cin >> n >> k;
    int p1, p2;
    --k;
    for (int i = n - 2; ~i; i--) {
      if (k < n - 1 - i) {
        p1 = i;
        p2 = n - 1 - k;
        break;
      }
      k -= (n - 1 - i);
    }
    for (int i = 0; i < n; i++) {
      if (i == p1 || i == p2)
        cout << "b";
      else {
        cout << "a";
      }
    }
    cout << endl;
  }
  return 0;
}
