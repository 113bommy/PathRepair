#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll getSum(ll x) { return (x + 1) * x / 2; }
ll sumTill(ll x, int need) {
  ll pw = 1;
  ll add = 0;
  ll cnt = 0;
  ll sum = 0;
  for (int len = 1;; len++) {
    if (pw * 10 - 1 <= x) {
      cnt = pw * 10 - pw;
      if (need) {
        sum += add * cnt + getSum(cnt) * len;
        add += cnt * len;
      } else {
        sum += cnt * len;
      }
    } else {
      cnt = x - pw + 1;
      if (cnt < 0) break;
      if (need) {
        sum += add * cnt + getSum(cnt) * len;
      } else {
        sum += cnt * len;
      }
    }
    pw *= 10;
  }
  return sum;
}
int main() {
  ll q, k;
  cin >> q;
  while (q--) {
    cin >> k;
    k--;
    ll l = 1, r = (ll)1e9;
    ll midAns = -1, ans;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      midAns = sumTill(mid, 1);
      if (midAns > k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    k -= sumTill(ans - 1, 1);
    ll num = -1;
    l = 1, r = ans;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      midAns = sumTill(mid, 0);
      if (midAns > k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    k -= sumTill(ans - 1, 0);
    cout << to_string(ans) << "\n";
  }
  return 0;
}
