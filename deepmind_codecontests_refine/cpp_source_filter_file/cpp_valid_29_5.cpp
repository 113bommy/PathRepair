#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;
const int N = 5e5 + 10;
struct Fenwick {
  long long ft[N];
  long long sum(int r) {
    long long result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += ft[r];
    return result;
  }
  long long sum(int l, int r) { return (l > r ? 0ll : sum(r) - sum(l - 1)); }
  void inc(int i, long long delta) {
    for (; i < N; i = (i | (i + 1))) ft[i] += delta;
  }
} ft1, ft2;
void solve() {
  int n;
  cin >> n;
  int MX = 3e5;
  long long pref = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans = ans + pref + x * 1ll * (i - 1) - ft1.sum(0, x - 1);
    for (int j = x; j <= MX; j += x) {
      int l = j;
      int r = min(MX, l + x - 1);
      ans -= ft2.sum(l, r) * j;
      ft1.inc(l, x);
    }
    ft2.inc(x, 1);
    cout << ans << " ";
    pref += x;
  }
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(10);
  int step = 1;
  for (int i = 0; i < step; i++) {
    solve();
  }
}
