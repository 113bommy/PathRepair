#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LINF = numeric_limits<long long>::max();
const double DINF = numeric_limits<double>::max();
const double eps = 1e-14;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
long long n, k;
long long Q[52];
bool is_pw_of_2(long long n) {
  long long res = 1;
  while (1) {
    if (res == n) {
      return true;
    }
    res *= 2;
    if (res > n) break;
  }
  return false;
}
long long pw2(long long n) {
  long long res = 1;
  for (int i = 0; i < n; i++) res *= 2;
  return res;
}
void solve() {
  cin >> n >> k;
  Q[1] = 1;
  for (long long i = 2; i < 52; i++) {
    Q[i] = Q[i - 1] * 2;
  }
  if (is_pw_of_2(k)) {
    long long res = 1, ans = 0;
    while (res <= k) {
      res *= 2;
      ans++;
    }
    cout << ans;
    return;
  }
  for (long long i = 1; i < 52; i++) {
    if ((k - Q[i]) % (Q[i] * 2) == 0) {
      cout << i;
      return;
    }
  }
}
int main() {
  if (!1) {
    freopen(
        "474"
        ".in",
        "r", stdin);
    freopen(
        "474"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = (228 & 322) >> 6;
  while (t--) solve();
  return 0;
}
