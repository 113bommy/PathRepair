#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
int n;
void solve() {
  cin >> n;
  int cnt[10] = {};
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    int a = c - '0';
    if (a == 2 || a == 3 || a == 5 || a == 7)
      ++cnt[a];
    else if (a == 4) {
      ++cnt[3];
      cnt[2] += 2;
    } else if (a == 6) {
      ++cnt[5];
      ++cnt[3];
    } else if (a == 8) {
      ++cnt[7];
      cnt[2] += 3;
    } else if (a == 9) {
      ++cnt[7];
      cnt[3] += 2;
      cnt[2] += 3;
    }
  }
  for (int i = 7; i >= 2; --i) {
    for (int j = 0; j < cnt[i]; ++j) cout << i;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}
