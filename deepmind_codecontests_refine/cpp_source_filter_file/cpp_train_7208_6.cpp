#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, m, k;
  int temp;
  while (t--) {
    cin >> n >> m >> k;
    temp = n / k;
    if (m <= temp)
      cout << m << endl;
    else {
      for (int i = 1; i <= k; i++) {
        if (m <= temp + i * (k - 1)) {
          cout << temp - i << endl;
          break;
        }
      }
    }
  }
  return 0;
}
