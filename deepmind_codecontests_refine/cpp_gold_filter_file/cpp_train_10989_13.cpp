#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long d[1000];
  d[1] = 2;
  d[2] = 3;
  for (long long i = 3; i < 1000; i++) d[i] = d[i - 1] + d[i - 2];
  for (long long i = 1; i < 1000; i++) {
    if (d[i] > n) {
      cout << i - 1;
      return 0;
    }
  }
  return 0;
}
