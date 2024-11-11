#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    vector<long long> indices[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      indices[a[i]].push_back(i);
    }
    long long k[n + 1];
    for (long long i = 0; i <= n; i++) k[i] = LONG_LONG_MAX;
    for (long long i = 1; i <= n; i++) {
      long long len = indices[i].size();
      if (len) {
        long long maxi = max(indices[i][0], n - indices[i][len - 1] + 1);
        for (long long j = 1; j < len; j++)
          maxi = max(maxi, indices[i][j] - indices[i][j - 1]);
        k[maxi] = min(k[maxi], i);
      }
    }
    long long flag = 1;
    for (long long i = 1; i <= n; i++) {
      if (k[i] == LONG_LONG_MAX and flag)
        cout << "-1 ";
      else {
        flag = 0;
        k[i] = min(k[i], k[i - 1]);
        cout << k[i] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
