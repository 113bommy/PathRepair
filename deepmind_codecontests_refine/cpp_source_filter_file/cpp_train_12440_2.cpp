#include <bits/stdc++.h>
using namespace std;
bool convert(long long int x) {
  while (x % 2 == 0) x /= 2;
  while (x % 3 == 0) x /= 3;
  return x;
}
void solve() {
  long long int a, b, c, n, nn, m, t, k, r, x, y, z, o, l,
      dd = 1000000, rr, i, sl, tl, d, mid, val, j, lo, h, e, tmp, cn, cf, flag,
      w, p;
  long long int ans = 0, cnt = 0;
  cin >> n;
  set<long long int> v;
  for (i = 0; i < n; i++) {
    cin >> a;
    m = convert(a);
    v.insert(m);
  }
  l = v.size();
  if (l == 1) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
