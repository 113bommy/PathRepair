#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> cnt;
void init() {
  cin >> n >> m;
  cnt.resize(m);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cnt[x - 1]++;
  }
}
void solve() {
  long long ans = 0, sum = 0;
  for (int i = 0; i < m; ++i) sum += cnt[i];
  for (int i = 0; i < m; ++i) ans = ans + (sum - cnt[i]) * cnt[i];
  cout << ans / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}
