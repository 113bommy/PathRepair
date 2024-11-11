#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll get_sum1(ll i) { return i * (i + 1) / 2; }
ll cal2(ll x) {
  ll ans = 0, i = 1, j = 1;
  for (; j * 10 <= x; i++, j *= 10) {
    ans += i * j * 9;
  }
  return ans + i * (x - j + 1);
}
ll cal1(ll x) {
  ll ans = 0, i = 1, j = 1;
  for (; j * 10 <= x; i++, j *= 10) {
    ans += i * get_sum1(j * 9) + i * j * 9 * (x - j * 10 + 1);
  }
  return ans + i * get_sum1(x - j + 1);
}
int main(int argc, char *argv[]) {
  ll q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    ll l = 0, r = 1e9, res1, res2;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (cal1(mid) < k) {
        l = mid + 1;
        res1 = mid;
      } else {
        r = mid - 1;
      }
    }
    k -= cal1(res1);
    l = 0, r = res1 + 1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (cal2(mid) < k) {
        l = mid + 1;
        res2 = mid;
      } else {
        r = mid - 1;
      }
    }
    k -= cal2(res2++);
    cout << to_string(res2)[k - 1] << endl;
  }
  return 0;
}
