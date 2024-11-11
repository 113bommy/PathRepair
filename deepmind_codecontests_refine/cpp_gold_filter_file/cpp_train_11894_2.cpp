#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n > 3) {
      if (n % 2 == 0) {
        for (long long i = 2; i <= n; i = i + 2) {
          cout << i << " ";
        }
        cout << n - 3 << " ";
        cout << n - 1 << " ";
        for (long long i = n - 5; i >= 1; i = i - 2) {
          cout << i << " ";
        }
        cout << endl;
      } else {
        for (long long i = 1; i <= n; i = i + 2) {
          cout << i << " ";
        }
        cout << n - 3 << " ";
        cout << n - 1 << " ";
        for (long long i = n - 5; i >= 2; i = i - 2) {
          cout << i << " ";
        }
        cout << endl;
      }
    } else {
      cout << -1 << endl;
    }
  }
}
