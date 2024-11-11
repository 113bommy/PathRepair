#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k % 3 == 0) {
      int t = n % (k + 1);
      if (t % 3 == 0 && t != k) {
        cout << "Bob";
      } else {
        cout << "Alice";
      }
    } else {
      if (n % 3 != 0) {
        cout << "Bob";
      } else {
        cout << "Alice";
      }
    }
    cout << endl;
  }
}
