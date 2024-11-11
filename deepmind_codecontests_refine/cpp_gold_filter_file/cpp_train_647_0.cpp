#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long A[n];
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (long long i = 0; i < 31; i++) {
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      if (A[j] > i) {
        sum = 0;
        continue;
      }
      sum += A[j];
      if (sum < 0) sum = 0;
      res = max(res, sum - i);
    }
  }
  cout << res;
  return 0;
}
