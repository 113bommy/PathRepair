#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  string a[n + 1];
  string b[k + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= k; i++) {
    cin >> b[i];
  }
  a[0] = a[n];
  b[0] = b[n];
  long long q;
  cin >> q;
  long long x;
  for (long long i = 0; i < q; i++) {
    cin >> x;
    long long m = x % n;
    long long o = x % k;
    cout << a[m] << b[o] << endl;
  }
  return 0;
}
