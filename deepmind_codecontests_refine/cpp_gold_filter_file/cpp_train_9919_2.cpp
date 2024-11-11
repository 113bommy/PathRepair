#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n <= 2) {
      cout << 1 << endl;
    } else {
      cout << (n - 3) / k + 2 << endl;
    }
  }
  return 0;
}
