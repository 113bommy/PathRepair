#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = n; i < m; i++) {
    long long f[10] = {0};
    long long temp = i;
    while (temp > 0) {
      f[temp % 10]++;
      temp /= 10;
    }
    bool flg = true;
    for (long long i = 0; i < 10; i++) {
      if (f[i] > 1) {
        flg = false;
      }
    }
    if (flg) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
