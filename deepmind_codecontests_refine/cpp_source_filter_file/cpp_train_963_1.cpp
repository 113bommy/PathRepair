#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l = 0, m, n, sum = 0, mx = -0x3f3f3f3f;
    cin >> n;
    long long md[1000000] = {0};
    for (i = 0; i < n; i++) {
      cin >> k;
      md[k]++;
    }
    for (i = 0; i <= 100; i++) {
      if (md[i] == 0 && l == 0) {
        sum = sum + 2 * i;
        break;
      }
      if (md[i] % 2 == 1 && l == 0) {
        sum = sum + i;
        l = 1;
      }
      if (l == 1 && md[i] == 0) {
        sum = sum + i;
        break;
      }
    }
    cout << sum << endl;
  }
}
