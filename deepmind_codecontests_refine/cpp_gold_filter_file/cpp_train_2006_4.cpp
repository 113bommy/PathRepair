#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k >= n) {
      cout << (k - n) << endl;
    } else {
      if ((n - k) % 2 == 1) {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    }
  }
  return 0;
}
