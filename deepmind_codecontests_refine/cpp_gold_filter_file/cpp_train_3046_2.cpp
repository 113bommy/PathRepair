#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
  ll n, k;
  cin >> n >> k;
  map<int, int> cnt;
  int cnt_max = 0, max_id = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x %= k;
    if (x) {
      x = k - x;
      cnt[x]++;
      if (cnt[x] > cnt_max) {
        cnt_max = cnt[x];
        max_id = x;
      }
      if (cnt[x] == cnt_max && x > max_id) {
        cnt_max = cnt[x];
        max_id = x;
      }
    }
  }
  if (cnt_max == 0) {
    cout << "0\n";
  } else {
    cout << (cnt_max - 1) * k + max_id + 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
