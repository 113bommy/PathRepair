#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 1e5 + 2;
int n, cnt[40], cnt1 = 0, mx;
ll a[N];
vector<ll> b;
bool ok(int num) {
  int cur = num;
  vector<ll> redun = b;
  vector<pair<int, ll> > lst;
  for (int i = (0); i <= (mx); ++i) {
    if (cur > cnt[i]) {
      lst.emplace_back(cur - cnt[i], (1LL << (i - 1)));
      cur = cnt[i];
    } else
      for (int j = (1); j <= (cnt[i] - cur); ++j) redun.emplace_back(1LL << i);
  }
  if (cur) lst.emplace_back(cur, (1LL << mx));
  if (((int)(redun).size()) > num) return 0;
  sort((redun).begin(), (redun).end(), greater<ll>());
  if (redun.empty()) return 1;
  int i = 0;
  reverse((lst).begin(), (lst).end());
  for (pair<int, ll> v : lst) {
    if (redun[i] >= v.second * 2) return 0;
    i += v.first;
    if (i >= ((int)(redun).size())) break;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i];
    int x = __builtin_ctz(a[i]);
    if (a[i] == (1LL << x))
      cnt[x]++, mx = max(mx, x);
    else
      b.emplace_back(a[i]);
  }
  int num = 0;
  cnt1 = cnt[0];
  int l = ((int)(b).size()), r = cnt1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m))
      r = m - 1;
    else
      l = m + 1;
  }
  if (l > cnt1)
    cout << -1;
  else
    for (int i = (l); i <= (cnt1); ++i) cout << i << ' ';
  return 0;
}
