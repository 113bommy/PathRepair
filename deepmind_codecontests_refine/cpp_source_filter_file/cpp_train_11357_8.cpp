#include <bits/stdc++.h>
using namespace std;
const int N = 302;
const long long base = 331;
const long long mod = 1e9 + 7;
int n, p[N], a[N], lenn[N];
long long hass[N], poww[N];
string s[N];
void readinp() {
  cin >> n;
  for (int i = int(1); i <= int(n); i++) cin >> s[i];
}
bool cmp(int i, int j) { return s[i] < s[j]; }
void compress() {
  for (int i = int(1); i <= int(n); i++) p[i] = i;
  sort(p + 1, p + 1 + n, cmp);
  int cnt = 0;
  for (int i = int(1); i <= int(n); i++) {
    if (i == 1 || s[p[i]] != s[p[i - 1]]) cnt++;
    a[p[i]] = cnt;
  }
}
void init() {
  lenn[0] = hass[0] = 0;
  poww[0] = 1;
  for (int i = int(1); i <= int(n); i++) {
    lenn[i] = (lenn[i - 1] + int(s[i].size()) + 1);
    poww[i] = (poww[i - 1] * base) % mod;
    hass[i] = (hass[i - 1] * base + a[i]) % mod;
  }
}
long long get(int i, int j) {
  return (hass[j] - hass[i - 1] * poww[j - i + 1] + mod * mod) % mod;
}
void solve() {
  compress();
  init();
  int res = lenn[n];
  for (int l = int(1); l <= int(n); l++) {
    for (int i = int(1); i <= int(n - l + 1); i++) {
      int j = i + l - 1;
      int k = j + 1;
      int cnt = 1;
      while (k + l - 1 <= n) {
        if (get(i, j) == get(k, k + l - 1)) {
          cnt++;
          k = k + l - 1;
        }
        k++;
      }
      if (cnt > 1) {
        res = min(res, lenn[n] - cnt * (lenn[j] - lenn[i - 1] - l - 1) - 1);
      }
    }
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("1003F"
            ".inp",
            "r")) {
    freopen(
        "1003F"
        ".inp",
        "r", stdin);
    freopen(
        "1003F"
        ".out",
        "w", stdout);
  }
  int t = 1;
  while (t--) {
    readinp();
    solve();
  }
}
