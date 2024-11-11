#include <bits/stdc++.h>
int dp[262145][2];
int ans = INT_MAX;
long long n;
using namespace std;
void fileio() {}
int main() {
  fileio();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1, q;
  cin >> T;
  while (T--) {
    long long n, x;
    cin >> n >> x;
    long long a[n];
    long long e = 0, ans = -1, sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == x) ans = 1;
      sum += (x - a[i]);
    }
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
        e = 1;
        break;
      }
    }
    if (!e)
      ans = 0;
    else if (ans == 1 || !sum)
      ans = 1;
    else
      ans = 2;
    cout << ans << "\n";
  }
  return 0;
}
