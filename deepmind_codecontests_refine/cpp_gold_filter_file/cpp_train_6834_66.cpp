#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  cin >> k;
  if (k > 36) {
    cout << -1 << endl;
  } else {
    long long m = k % 2;
    if (m == 0) {
      for (long long i = 0; i < k / 2; i++) {
        cout << "8";
      }
      cout << endl;
    } else {
      for (long long i = 0; i < k / 2; i++) {
        cout << "8";
      }
      cout << "6" << endl;
    }
  }
}
