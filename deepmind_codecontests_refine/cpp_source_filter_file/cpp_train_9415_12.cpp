#include <bits/stdc++.h>
using namespace std;
int n, d, a[1000], ans, cnt;
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  ans = 0;
  cnt = a[0];
  if (a[0] < d) {
    cout << "-1";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (cnt + a[i] + 10 <= d) {
      cnt += a[i] + 10;
      ans += 2;
    } else {
      cout << "-1";
      return 0;
    }
  }
  while (cnt + 5 <= d) {
    cnt += 5;
    ans++;
  }
  cout << ans;
}
