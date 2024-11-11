#include <bits/stdc++.h>
using namespace std;
long long a[2001][2001];
long long cost[2001][2001];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) {
      cin >> a[i][j];
      cost[i][j] = -a[i][j];
    }
  for (long long j = 1; j <= n; j++) {
    long long res = 0;
    for (long long i = 0; j + i <= n; i++) res += a[i + 1][j + i];
    for (long long i = 0; j + i <= n; i++) cost[i + 1][j + i] += res;
  }
  for (long long i = 2; i <= n; i++) {
    long long res = 0;
    for (long long j = i; j <= n; j++) res += a[j][j - i + 1];
    for (long long j = i; j <= n; j++) cost[j][j - i + 1] += res;
  }
  for (long long j = n; j >= 1; j--) {
    long long res = 0;
    for (long long i = 0; j - i >= 1; i++) res += a[i + 1][j - i];
    for (long long i = 0; j - i >= 1; i++) cost[i + 1][j - i] += res;
  }
  for (long long i = 2; i <= n; i++) {
    long long res = 0;
    for (long long j = i; j <= n; j++) res += a[j][n - j + i];
    for (long long j = i; j <= n; j++) cost[j][n - j + i] += res;
  }
  long long resodd = 0;
  long long reseven = 0;
  long long xodd, yodd, xeven, yeven;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if ((i + j) & 1 && cost[i][j] > resodd) {
        resodd = cost[i][j];
        xodd = i;
        yodd = j;
      }
      if ((i + j) % 2 == 0 && cost[i][j] > reseven) {
        reseven = cost[i][j];
        xeven = i;
        yeven = j;
      }
    }
  }
  cout << reseven + resodd << '\n';
  cout << xodd << " " << yodd << " " << xeven << " " << yeven << '\n';
  return 0;
}
