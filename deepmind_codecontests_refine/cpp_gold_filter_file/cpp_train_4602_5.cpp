#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, m, count1 = 0, count2 = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x % 2 == 0) {
        count1++;
      }
    }
    cin >> m;
    for (i = 0; i < m; i++) {
      long long y;
      cin >> y;
      if (y % 2 == 0) {
        count2++;
      }
    }
    cout << (count1 * count2) + ((n - count1) * (m - count2)) << endl;
  }
}
