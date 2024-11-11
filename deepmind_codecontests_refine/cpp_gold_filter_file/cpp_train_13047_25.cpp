#include <bits/stdc++.h>
using namespace std;
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
pair<pair<int, int>, int> ar[tam];
int res[tam];
int n, k, h;
bool first(double t) {
  int mul = 1;
  for (int i = 0, asdz = n; i < asdz; i++) {
    if (mul <= k && mul * h <= ar[i].first.second * t) {
      res[mul - 1] = ar[i].second + 1;
      mul++;
    }
  }
  return mul > k;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> h;
  for (int i = 0, asdz = n; i < asdz; i++) {
    cin >> ar[i].first.first;
    ar[i].second = i;
  }
  for (int i = 0, asdz = n; i < asdz; i++) cin >> ar[i].first.second;
  sort(ar, ar + n);
  double lo = 0, hi = 1000000000, mid, resp;
  for (int i = 0, asdz = 100; i < asdz; i++) {
    mid = (lo + hi) / 2;
    if (first(mid))
      resp = mid, hi = mid;
    else
      lo = mid;
  }
  assert(first(resp));
  for (int i = 0, asdz = k; i < asdz; i++) {
    if (i > 0) cout << ' ';
    cout << res[i];
  }
  cout << '\n';
  return 0;
}
