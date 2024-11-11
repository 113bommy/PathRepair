#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int mod = 1e9 + 7;
const int mex = 2002;
long long arr[mex][mex];
long long dp1[mex], dp2[mex];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long s = 0, e = 2 * 1e9 + 5, id = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < i; j++) {
      long long h = abs(a[i] - a[j]) / (i - j);
      if (abs(a[i] - a[j]) % (i - j)) h++;
      arr[i][j] = h;
    }
  while (s <= e) {
    long long md = (s + e) / 2, fg = 0;
    dp1[0] = 0;
    for (long long i = 1; i < n; i++) {
      dp1[i] = i;
      for (long long j = 0; j < i; j++) {
        long long h = arr[i][j];
        if (h <= md) {
          dp1[i] = min(dp1[i], dp1[j] + (i - j - 1));
        }
      }
    }
    dp2[n - 1] = 0;
    for (long long i = n - 2; i >= 0; i--) {
      dp2[i] = n - 1 - i;
      for (long long j = n - 1; j >= i + 1; j--) {
        long long h = arr[j][i];
        if (h <= md) {
          dp2[i] = min(dp2[i], dp2[j] + (j - i - 1));
        }
      }
      if ((dp1[i] + dp2[i]) <= k) fg = 1;
    }
    if (fg) {
      e = md - 1;
      id = md;
    } else
      s = md + 1;
  }
  cout << id << "\n";
}
