#include <bits/stdc++.h>
using namespace std;
long long logPow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
    }
    a *= a;
    b = b >> 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long s_x, s_y;
  cin >> s_x >> s_y;
  long long c_x = s_x, c_y = s_y;
  long long k;
  cin >> k;
  long long arr[10005][2];
  for (long long i = 0; i < k; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  long long ans = 0;
  for (long long i = 0; i < k; i++) {
    long long mn_x = INT_MAX, mn_y = INT_MAX;
    if (arr[i][0] < 0) {
      mn_x = (c_x - 1) / abs(arr[i][0]);
    } else if (arr[i][0] > 0) {
      mn_x = (n - c_x) / arr[i][0];
    }
    if (arr[i][1] < 0) {
      mn_y = (c_y - 1) / abs(arr[i][1]);
    } else if (arr[i][1] > 0) {
      mn_y = (n - c_y) / arr[i][1];
    }
    long long cnt = min(mn_x, mn_y);
    ans += cnt;
    c_x += cnt * arr[i][0];
    c_y += cnt * arr[i][1];
  }
  cout << ans << "\n";
  return 0;
}
