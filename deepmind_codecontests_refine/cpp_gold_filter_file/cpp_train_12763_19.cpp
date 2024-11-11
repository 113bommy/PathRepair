#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
constexpr int N = 1000010;
constexpr ll INFL = 1000000000000000000;
int n, p[N];
int a[2 * N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  int pos = 0;
  ll ans = 0, ansj = 0;
  for (int i = 1; i <= n; ++i) {
    ans += abs(p[i] - i);
    if (p[i] - i > 0) {
      ++pos;
      ++a[p[i] - i];
    }
  }
  ll cur = ans;
  for (int j = 1; j < n; ++j) {
    int ind = n + 1 - j;
    cur += n - 1 - 2 * pos + (abs(p[ind] - 1) - abs(p[ind] - n));
    if (cur < ans) {
      ans = cur;
      ansj = j;
    }
    if (p[ind] - ind > 0) --a[p[ind] - ind];
    pos -= a[j];
    if (p[ind] - 1 > 0) {
      ++pos;
      ++a[p[ind] - 1 + j];
    }
  }
  cout << ans << ' ' << ansj;
}
