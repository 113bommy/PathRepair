#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long bin_pow(long long n, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = (ret * n) % mod;
    n = (n * n) % mod;
    k /= 2;
  }
  return ret;
}
int main() {
  int n, n1;
  cin >> n1;
  vector<vector<int> > a(n1);
  n = (n1 / 2) * 2;
  int l = 1, r = n1 * n, c = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n; j++) {
      if (c % 2) {
        cout << l << " ";
        l++;
      } else {
        cout << r << " ";
        r--;
      }
      c++;
    }
    if (n1 % 2) {
      cout << n1 * n + i + 1 << " ";
    }
    cout << endl;
  }
}
