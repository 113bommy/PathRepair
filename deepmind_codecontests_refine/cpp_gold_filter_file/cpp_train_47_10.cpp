#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vl xi(n), hi(n);
  for (int i = (0); i < (n); ++i) cin >> xi[i] >> hi[i];
  int ans = 1;
  int prev = 0;
  for (int i = (1); i < (n - 1); ++i) {
    if (prev == 0) {
      if (xi[i] - hi[i] > xi[i - 1])
        ans++;
      else if (xi[i] + hi[i] < xi[i + 1]) {
        prev = 1;
        ans++;
      }
    } else if (prev == 1) {
      if (xi[i] - hi[i] > xi[i - 1] + hi[i - 1]) {
        prev = 0;
        ans++;
      } else if (xi[i] + hi[i] < xi[i + 1])
        ans++;
      else
        prev = 0;
    }
  }
  if (n >= 2) ans++;
  cout << ans;
  return 0;
}
