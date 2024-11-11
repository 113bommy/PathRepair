#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1e3 + 5;
ll n, q, l, r, mid, ans, temp;
ll get(ll v) {
  ll deg = 10, l = 1, r = 9, sum = 0, len = 1, num = 9;
  while (deg < v) {
    sum += ((l + r) * num) >> 1;
    if (sum >= n) return LLONG_MAX;
    deg *= 10;
    num *= 10;
    len++;
    l = r + len, r = l + len * (num - 1);
  }
  deg /= 10;
  r = l + len * ((v - deg));
  sum += ((l + r) * (v - deg + 1)) >> 1;
  return sum;
}
ll getans(ll x, ll v) {
  if (x == 0) {
    return v % 10;
  }
  ll deg = 10, l = 1, r = 9, sum = 0, len = 1, num = 9, lastl, lastr;
  while (sum < x) {
    sum += len * num;
    deg *= 10;
    num *= 10;
    len++;
    lastl = l, lastr = r;
    l = r + 1, r = l + (num - 1);
  }
  if (sum == x) return 9;
  num /= 10;
  len--;
  sum -= len * num;
  x -= sum;
  lastl += x / len;
  if (x % len) {
    return to_string(lastl)[(x % len) - 1] - '0';
  } else
    return to_string(lastl - 1).back() - '0';
}
void Solve() {
  cin >> q;
  while (q--) {
    cin >> n;
    l = 1, r = 1e9;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (get(mid) <= n) {
        ans = mid, l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << getans(n - get(ans), ans) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
