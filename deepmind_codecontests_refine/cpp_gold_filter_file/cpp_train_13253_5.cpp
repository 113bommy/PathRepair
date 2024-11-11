#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long n, m, k;
int main() {
  cin >> n >> m >> k;
  if (k == 1 || k > n) {
    long long r = 1;
    for (int i = 0; i < n; i++) r = (r * m) % mod;
    cout << r << endl;
  } else if (k == n) {
    long long r = 1;
    for (int i = 0; i < (n + 1) / 2; i++) r = (r * m) % mod;
    cout << r << endl;
  } else {
    if (k % 2 == 0)
      cout << m << endl;
    else {
      long long r = m * (m) % mod;
      cout << r << endl;
    }
  }
  return 0;
}
