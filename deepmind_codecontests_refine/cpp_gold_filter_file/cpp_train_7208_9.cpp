#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int e = n / k;
    if (m <= e) {
      cout << m << "\n";
    } else {
      int flag = 0;
      if ((m - e) % (k - 1) != 0) {
        flag = 1;
      }
      cout << (e - (((m - e) / (k - 1)) + flag)) << "\n";
    }
  }
  return 0;
}
