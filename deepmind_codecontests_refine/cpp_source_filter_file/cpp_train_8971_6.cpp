#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1e9 + 7;
int n, m;
vector<int> guess;
void solve() {
  deque<int> d;
  for (int i = 1; i <= n; ++i) {
    d.push_back(i);
  }
  int x = 0;
  for (int i = m - 1; i >= 0; --i) {
    d.pop_back();
    d.push_front(x);
    if (guess[i] + 1 < n) d[guess[i]] = d[guess[i] + 1];
    --x;
  }
  d.pop_back();
  d.push_front(x);
  deque<int> f;
  for (int i = 1; i <= n; ++i) {
    f.push_back(i);
  }
  x = n + 1;
  for (int i = m - 1; i >= 0; --i) {
    f.pop_front();
    f.push_back(x);
    ++x;
    if (guess[i] - 1 >= 0) f[guess[i]] = f[guess[i] - 1];
  }
  f.pop_front();
  f.push_back(x);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    f[i] = min(n, f[i]);
    d[i] = max(1, d[i]);
    ans += min(n, f[i] - d[i] + 1);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  if (n == m && n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int g;
    cin >> g;
    g--;
    guess.push_back(g);
  }
  solve();
  return 0;
}
