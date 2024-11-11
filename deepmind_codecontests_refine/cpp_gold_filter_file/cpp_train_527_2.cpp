#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long test, n, m, k, x, y, ans, b[N], a[N];
void solve() {
  string s, t;
  cin >> n >> m;
  char ch;
  for (long long i = 1; i <= n; i++) cin >> ch, a[ch - 'a']++;
  for (long long i = 0; i <= 25; i++) {
    if (a[i]) t.push_back('a' + i), ans += i + 1, i += 1;
    if (t.size() == m) break;
  }
  if (t.size() == m)
    cout << ans;
  else
    cout << -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
