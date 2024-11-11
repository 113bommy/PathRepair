#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;
int used[1010];
int ans[1010][1010];
int h[1010];
int n;
int cur;
void solve() {
  int ma = 0;
  for (int i = (int)(0); i < (int)(n); ++i) {
    if (!used[i]) ma = max(h[i], ma);
  }
  if (ma == 0) return;
  vector<int> ms;
  for (int i = (int)(0); i < (int)(n); ++i) {
    if (!used[i] && h[i] == ma) ms.push_back(i);
  }
  for (int j = (int)(0); j < (int)(ms.size()); ++j) {
    for (int i = (int)(0); i < (int)(ma); ++i) {
      ans[(cur - i - j + 2 * cur + 1) % (cur + 1)][ms[j]] = 1;
    }
  }
  for (int i = (int)(0); i < (int)(ms.size()); ++i) used[ms[i]] = 1;
  cur = cur - ms.size();
  for (int i = (int)(0); i < (int)(n); ++i) {
    if (!used[i] && h[i] > cur) {
      for (int j = (int)(0); j < (int)(h[i] - cur); ++j)
        ans[j + cur + 1][i] = 1;
      h[i] = cur;
    }
  }
  solve();
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (int)(0); i < (int)(n); ++i) cin >> h[i];
  cur = n;
  solve();
  cout << n + 1 << endl;
  for (int i = (int)(0); i < (int)(n + 1); ++i) {
    for (int j = (int)(0); j < (int)(n); ++j) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}
