#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, j;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long n, s, k;
    cin >> n >> s >> k;
    long long arr[k];
    map<long long, long long> m;
    for (j = 0; j < k; j++) {
      long long x;
      cin >> x;
      m[x] = 1;
    }
    long long res = 999999999;
    for (j = s; j >= 1; j--) {
      if (m[j] == 0) {
        res = s - j;
        break;
      }
    }
    for (j = s; j <= n; j++) {
      if (m[j] == 0) {
        res = min(j - s, res);
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
