#include <bits/stdc++.h>
using namespace std;
void work() {
  long long n, l, r;
  cin >> n >> l >> r;
  long long cnt = 0;
  long long sum = 0;
  long long f = 0;
  for (long long i = n - 1; i > 0; i--) {
    sum += i * 2;
    cnt++;
    if (sum > l) {
      sum -= i * 2;
      f = 1;
      break;
    }
  }
  if (f == 0) {
    if (l == sum + 1) cout << 1 << endl;
    return;
  }
  vector<long long> ans;
  long long fl = l % 2;
  long long now = cnt + fl + (l - sum) / 2;
  for (long long i = l; i <= r; i++) {
    if (fl == 1) {
      if (cnt == n) {
        ans.push_back(1);
        break;
      }
      ans.push_back(cnt);
      fl = 0;
    } else {
      fl = 1;
      ans.push_back(now);
      if (now == n) {
        cnt++;
        now = cnt + 1;
      } else
        now++;
    }
  }
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    work();
  }
  return 0;
}
