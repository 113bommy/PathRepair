#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
const int MAX = 555;
const int MAS = 1e4;
const int MOD = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-8;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  vector<long long> mix, men;
  long long cnt = 0;
  for (int j = (0); j < (n); j++) {
    int x;
    bool ok = false;
    cin >> x;
    int mn = INF;
    int mx = -INF;
    vector<int> a(x);
    for (int i = (0); i < (x); i++) {
      cin >> a[i];
      if (i > 0) {
        if (a[i] > mn) {
          ok = true;
        }
      }
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
    if (ok) {
      ans += n * 2, cnt++;
    } else {
      mix.emplace_back(mx);
      men.emplace_back(mn);
    }
  }
  ans -= cnt * cnt;
  sort(men.begin(), men.end());
  for (int i = (0); i < (mix.size()); i++) {
    auto t = lower_bound(men.begin(), men.end(), mix[i]);
    ans += (t - men.begin());
  }
  cout << ans;
}
