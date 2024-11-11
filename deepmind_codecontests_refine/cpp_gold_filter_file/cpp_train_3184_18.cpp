#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 2e18;
string s;
ll n, ts, tf, t, a[MAXN], prev_t, firs, b[MAXN], c, timer, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> ts >> tf >> t >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a[n] = timer = LLINF;
  ll bor = ts;
  for (int i = 0; i < n + 1; i++) {
    if (bor < a[i]) {
      timer = 0;
      ans = bor;
      break;
    }
    if (a[i] > 0) {
      ll x = a[i] - 1, y;
      if (x + t <= tf) {
        y = max(bor - x, 0LL);
        if (timer > y) {
          timer = y;
          ans = x;
        }
      }
    }
    bor = max(bor, a[i]) + t;
    if (bor + t > tf) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
