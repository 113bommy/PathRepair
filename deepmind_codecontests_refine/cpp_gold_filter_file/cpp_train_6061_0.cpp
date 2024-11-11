#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 != 0) {
      cout << 7;
      n = n - 3;
    }
    while (n > 0) {
      cout << 1;
      n = n - 2;
    }
    cout << endl;
  }
  return 0;
}
