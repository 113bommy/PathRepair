#include <bits/stdc++.h>
using namespace std;
inline long long MIN(long long a, long long b) { return a > b ? b : a; }
inline long long MAX(long long a, long long b) { return a > b ? a : b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long arr[2][2];
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      cin >> arr[i][j];
    }
  }
  long long n;
  cin >> n;
  long long v[3], ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 3; j++) {
      cin >> v[j];
    }
    long long val1 = v[0] * arr[0][0] + v[1] * arr[0][1] + v[2];
    long long val2 = v[0] * arr[1][0] + v[1] * arr[1][1] + v[2];
    if ((val1 < 0 && val1 > 0) || (val1 > 0 && val2 < 0)) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
