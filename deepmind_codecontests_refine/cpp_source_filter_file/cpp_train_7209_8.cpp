#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, m;
struct uzi {
  int x, y;
  bool operator<(const uzi &t) const { return x > t.x; }
} p[N];
int s[N];
long long su[N];
int main() {
  ios::sync_with_stdio(false);
  for (cin >> t; t; t--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> p[i].x >> p[i].y;
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; i++) s[i] = p[i].x, su[i] = su[i - 1] + p[i].x;
    long long ans = 0;
    auto get = [&](int x) {
      int l = 1, r = m, ans = 0;
      while (l <= r) {
        int mid = l + r >> 1;
        if (s[mid] >= x)
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      return ans;
    };
    for (int i = 1; i <= m; i++) {
      int pos = get(p[i].y);
      if (n <= pos) {
        assert(n <= m);
        ans = max(ans, su[n]);
        continue;
      }
      long long _su = su[pos];
      if (p[i].x >= p[i].y) pos--, _su -= p[i].x;
      pos++;
      _su += p[i].x;
      ans = max(ans, _su + (n - pos) * p[i].y);
    }
    cout << ans << '\n';
  }
  return 0;
}
