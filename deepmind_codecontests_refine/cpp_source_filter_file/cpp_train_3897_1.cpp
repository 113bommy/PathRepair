#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long p[k + 1][n];
  for (long long i = 0; i <= k; i++) p[i][0] = 0;
  for (long long j = 0; j < n; j++) p[0][j] = 0;
  for (long long i = 1; i <= k; i++) {
    long long pr = INT_MIN;
    for (long long j = 1; j < n; j++) {
      pr = max(pr, p[i - 1][j - 1] - a[j - 1]);
      p[i][j] = max(p[i][j - 1], pr + a[j]);
    }
  }
  cout << p[k][n - 1];
  return 0;
}
