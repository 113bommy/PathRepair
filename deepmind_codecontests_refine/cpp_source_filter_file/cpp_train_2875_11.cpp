#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n = 0, k = 0;
  cin >> n >> k;
  if (n == 1) {
    cout << "0"
         << " "
         << "0" << endl;
  } else {
    if (k == 0 || n == k) {
      cout << "0"
           << " "
           << "0" << endl;
    } else {
      cout << "1"
           << " ";
      if (n / 2 >= k) {
        cout << k + 1 << endl;
      } else {
        cout << n - k << endl;
      }
    }
  }
  return 0;
}
