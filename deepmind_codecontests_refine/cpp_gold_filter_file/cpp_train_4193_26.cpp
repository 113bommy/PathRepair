#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    char arr[n][m];
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) cin >> arr[i][j];
    long long ans = 0;
    for (long long i = 0; i < n; i++)
      if (arr[i][m - 1] == 'R') ans++;
    for (long long i = 0; i < m; i++)
      if (arr[n - 1][i] == 'D') ans++;
    cout << ans << endl;
  }
  return 0;
}
