#include <bits/stdc++.h>
using namespace std;
long long gc(long long n, int k);
int main() {
  long long int t;
  cin >> t;
  for (long long int j = 0; j < t; j++) {
    long long int n, m, k, min = INT64_MAX;
    cin >> n >> k;
    long long int sum = 0;
    int c = (int)log2(k) + 1;
    ;
    for (int i = 0; i <= c; i++) {
      long long int z = k - n + 1 - (gc(k + 1, i) - gc(n, i));
      if (n != 1 && (z) < min) {
        min = z;
      } else if (n == 1) {
        z = k - gc(k + 1, i);
        if ((z) < min) {
          min = z;
        }
      }
    }
    cout << min << "\n";
  }
  return 0;
}
long long gc(long long n, int k) {
  long long res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) res += n & ((1ll << k) - 1);
  return res;
}
