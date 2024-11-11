#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int a, int b) {
  int x = uniform_int_distribution<int>(a, b)(rng);
  return x;
}
vector<int> pos[N];
int a[N];
void TEST_CASES() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int ans = 1e9;
    l--;
    r--;
    int koto = (r - l + 1) / k;
    for (int i = 0; i <= 60; i++) {
      int x = getrand(l, r);
      int id = lower_bound(pos[a[x]].begin(), pos[a[x]].end(), l) -
               pos[a[x]].begin();
      int ses = id + koto;
      if (ses < pos[a[x]].size() && pos[a[x]][ses] <= r) {
        ans = min(ans, a[x]);
      }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
