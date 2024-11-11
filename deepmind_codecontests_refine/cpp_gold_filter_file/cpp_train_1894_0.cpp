#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long int n, j, s = 0, i;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> j;
      if (j <= 2048) {
        s = s + j;
      }
    }
    if (s >= 2048) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
