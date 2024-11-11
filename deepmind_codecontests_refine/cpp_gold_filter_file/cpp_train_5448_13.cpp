#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e6 + 6;
int la, lb;
int a[N], b[N], p[N];
bool lil(int l, int i, int r) {
  if (l <= r) {
    return l <= i && i <= r;
  }
  return l <= i || i <= r;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> la >> lb;
  for (int i = 1; i <= la; ++i) {
    cin >> a[i];
    a[i + la] = a[i];
  }
  for (int i = 1; i <= lb; ++i) {
    cin >> b[i];
    p[b[i]] = i;
  }
  int ans = 0, j = 2;
  for (int i = 1; i <= la; ++i) {
    if (p[a[i]]) {
      if (j < i + 1) {
        j = i + 1;
      }
      while (j - i < la && p[a[j]] && !lil(p[a[i]], p[a[j]], p[a[j - 1]])) {
        ++j;
      }
      ans = max(ans, j - i);
    }
  }
  cout << ans;
}
