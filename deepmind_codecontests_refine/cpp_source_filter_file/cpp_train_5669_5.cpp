#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1), eps = 1e-9;
const int mxa = 1e3;
const int mxn = 5e3, mxm = 2e5, mxk = 18;
int n, a[mxn];
int calc(int l, int r, int h) {
  int ans = 0;
  for (int i = l; i <= r; ++i) a[i] -= h;
  for (int i = l; i <= r; ++i) {
    if (a[i] == 0) continue;
    int start = i;
    while (i + 1 <= r && a[i + 1]) ++i;
    int add = *min_element(a + start, a + i + 1);
    ans += min(r - start + 1, add + calc(start, i, add));
  }
  return ans;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << calc(0, n - 1, 0) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  tt = 1;
  while (tt-- > 0) solve();
}
