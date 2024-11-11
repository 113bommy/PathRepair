#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
using ll = long long;
int n, a[N];
ll kk, b, l, r;
set<ll> s;
inline bool find(ll x) { return (l <= x && x <= r) || s.count(kk * (x - b)); }
ll stk[N], top;
void del(ll x) {
  top = 0;
  if (s.empty()) return;
  if (kk == 1) {
    auto it = s.lower_bound(x - b);
    while (it != s.end()) stk[++top] = *it++;
  } else {
    auto it = s.upper_bound(b - x);
    if (it == s.begin()) return;
    --it;
    while (it != s.begin()) stk[++top] = *it--;
    if (it == s.begin()) stk[++top] = *it;
  }
  while (top) s.erase(stk[top--]);
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    int ans = 0;
    l = INT_MAX;
    r = 1;
    kk = 1;
    b = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 0) {
        del(a[i]);
        int t = a[i] / 2;
        if (find(t))
          s.clear(), ans += 2, s.insert(kk * (t - b)), l = INT_MAX, r = 1;
        else {
          ++ans;
          s.insert(kk * (t - b));
          l = a[i] - l;
          r = a[i] - r;
          swap(l, r);
          l = max(l, 1ll);
          if (l > r) l = INT_MAX, r = 1;
        }
      } else {
        del(a[i]);
        l = a[i] - l;
        r = a[i] - r;
        bool fl = 1;
        swap(l, r);
        l = max(l, 1ll);
        if (l > r) l = INT_MAX, r = 1, fl = 0;
        if (s.empty()) {
          if (fl)
            ++ans;
          else
            l = 1, r = a[i] - 1;
        } else
          ++ans;
      }
      kk *= -1;
      b = -b + a[i];
    }
    cout << n * 2 - ans << endl;
    s.clear();
  }
  return 0;
}
