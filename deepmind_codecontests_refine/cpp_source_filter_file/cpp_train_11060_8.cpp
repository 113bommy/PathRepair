#include <bits/stdc++.h>
using namespace std;
long long t;
int main() {
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if ((n / 2) % 2 == 0) {
      cout << "Yes" << endl;
      for (int i = 2; i < n + 1; i += 2) {
        cout << i << " ";
      }
      for (int i = 1; i < n - 1; i += 2) {
        cout << i << " ";
      }
      cout << n + 1;
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
