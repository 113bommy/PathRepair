#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    bool z = false;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < n && !z; i++) {
      int sum = 0;
      for (int j = i; j <= n && !z; j++) {
        sum += v[j];
        if (sum % 2 == 0) {
          z = true;
          cout << j - i + 1 << endl;
          for (int k = i; k <= j; k++) {
            cout << k + 1 << " ";
          }
          cout << endl;
        }
      }
    }
    if (!z) {
      cout << -1 << endl;
    }
  }
  return 0;
}
