#include <bits/stdc++.h>
using namespace std;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  sort(a.rbegin(), a.rend());
  if (m <= k)
    cout << a[0] * m;
  else
    cout << (a[0] * k + a[1]) * (m / (k + 1)) + (a[0] * k) * (m % (k + 1));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
