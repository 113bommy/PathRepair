#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(2 * n, 0);
  for (long long i = 0; i < (2 * n); i++) {
    a[i] = i + 1;
  }
  long long i = 0;
  while (i < k) {
    long long t = a[i];
    a[i] = a[i + 1];
    a[i + 1] = t;
    i += 2;
  }
  for (long long i = 0; i < (2 * n); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}
