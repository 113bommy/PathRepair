#include <bits/stdc++.h>
using namespace std;
int n;
long long ans1 = 1, ans2 = 1, ans3 = 1;
long long fact[400400];
int a[400400], b[400400];
pair<int, int> c[400400];
const long long mod = 998244353;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    c[i] = make_pair(a[i], b[i]);
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1);
  int cnt = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i - 1]) {
      ++cnt;
    } else {
      ans1 = (ans1 * fact[cnt]) % mod;
      cnt = 1;
    }
  }
  if (cnt > 0) ans1 = (ans1 * fact[cnt]) % mod;
  cnt = 1;
  for (int i = 2; i <= n; ++i) {
    if (b[i] == b[i - 1]) {
      ++cnt;
    } else {
      ans2 = (ans2 * fact[cnt]) % mod;
      cnt = 1;
    }
  }
  if (cnt > 0) ans2 = (ans2 * fact[cnt]) % mod;
  bool can = true;
  for (int i = 2; i <= n; ++i) {
    if (c[i].second < c[i - 1].second) {
      can = false;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j <= n && c[j].first == c[i].first) ++j;
    --j;
    cnt = 1;
    for (int k = i + 1; k <= j; ++k) {
      if (c[k].second == c[k - 1].second) {
        ++cnt;
      } else {
        ans3 = (ans3 * fact[cnt]) % mod;
        cnt = 1;
      }
    }
    if (cnt > 0) ans3 = (ans3 * fact[cnt]) % mod;
    i = j;
  }
  if (can == false) ans3 = 0;
  long long ans = (ans1 + ans2 - ans3 + mod) % mod;
  ans = (fact[n] - ans + mod) % mod;
  cout << ans << "\n";
  return 0;
}
