#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n + 10];
    long long pos[n + 10];
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
      pos[arr[i]] = i;
    }
    long long flag = 1;
    long long ind = 1;
    long long tot = 0;
    while (true) {
      if (tot == n) break;
      long long val = pos[ind];
      long long j;
      long long p = tot;
      if (val == n) {
        ++tot;
        ind = arr[val] + 1;
        continue;
      }
      for (j = val; j < n - p; j++) {
        if (arr[j + 1] - arr[j] != 1) {
          flag = 0;
          break;
        }
        ind = arr[j + 1] + 1;
        ++tot;
      }
      ++tot;
    }
    if (flag == 0)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}
