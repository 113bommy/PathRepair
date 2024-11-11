#include <bits/stdc++.h>
using namespace std;
int n, m, mas[5];
void init() { cin >> n >> m; }
void solve() {
  int cnt = 0;
  for (int i = 1; i <= m; ++i) mas[i % 5]++;
  for (int i = 1; i <= n; ++i) cnt += mas[(5 - i % 5) % 5];
  cout << cnt;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  init();
  solve();
  return 0;
}
