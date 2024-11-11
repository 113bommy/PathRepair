#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N];
long long ksm(long long a, long long b, long long c) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return res % c;
}
int read() {
  int n;
  cin >> n;
  return n;
}
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int pos = 0;
  vector<long long> v;
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1 && a[i] != 0) {
      cout << 0 << '\n';
      return;
    }
    v.push_back(min(ksm(10, a[i] - pos, 1e18) - 1, k));
    if (k + 1 == ksm(10, a[i] - pos, 1e18)) f = true;
    k = max(0ll, k - ksm(10, a[i] - pos, 1e18) + 1);
    if (k == 0) break;
    pos = a[i];
  }
  if (v.size() == 1) {
    cout << v[0] + k + 1 << '\n';
    return;
  }
  if (k != 0) {
    v.push_back(k);
    v.back()++;
    for (int i = v.size() - 1; i > 0; i--) cout << v[i];
    cout << '\n';
    return;
  }
  if (k == 0) {
    if (!f) {
      v.back()++;
    } else
      v.push_back(1);
  }
  for (int i = v.size() - 1; i > 0; i--) cout << v[i];
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
