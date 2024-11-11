#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n == 0) {
      cout << m + 1 << endl;
      continue;
    }
    bitset<35> b(n);
    long long high = 1;
    long long cnt = 0;
    while (high <= max(n + 1, m + 1)) {
      high *= 2;
      cnt++;
    }
    cnt--;
    long long l = 0, r = high - 1;
    bitset<35> ans;
    for (long long i = cnt; i >= 0; i--) {
      long long mid = (l + r) / 2;
      if (mid > m) {
        ans[i] = 0;
        if (b[i] == 0) {
          r = mid;
        } else {
          l = mid + 1;
        }
      } else {
        if (b[i] == 0) {
          ans[i] = 1;
        } else {
          ans[i] = 0;
        }
        l = mid + 1;
      }
    }
    long long ans_num = 0;
    for (long long i = 0; i <= cnt; i++) {
      ans_num += (ans[i] << i);
    }
    cout << ans_num << endl;
  }
}
