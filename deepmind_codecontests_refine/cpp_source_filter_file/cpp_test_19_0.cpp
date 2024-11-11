#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 1e4 + 5;
int a[MX];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 1, h = 1500;
    while (l < h) {
      int m = (l + h) / 2;
      bitset<1505> bs, mask;
      for (int i = 0; i <= m; ++i) bs[i] = mask[i] = 1;
      for (int i = 0; i < n; ++i) bs = ((bs << a[i]) | (bs >> a[i])) & mask;
      if (bs.count() > 0)
        h = m;
      else
        l = m + 1;
    }
    cout << l << '\n';
  }
}
