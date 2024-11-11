#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    bool flag = false;
    if (n % 2 == 0 && k % 2 == 0) {
      flag = true;
    } else if (n % 2 != 0 && k % 2 != 0) {
      flag = true;
    }
    if (k * k > n) {
      flag = false;
    }
    if (flag) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
