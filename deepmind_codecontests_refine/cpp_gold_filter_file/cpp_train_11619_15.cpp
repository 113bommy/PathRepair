#include <bits/stdc++.h>
using namespace std;
long long n, k;
void solve() {
  cin >> n >> k;
  vector<int> p(n + 1), dup(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    dup[i] = p[i];
  }
  while (k--) {
    int l, r, x;
    cin >> l >> r >> x;
    int px = p[x];
    int cnt = 0;
    for (int i = l; i <= r; i++) {
      if (px > p[i]) cnt++;
    }
    int now = l + cnt;
    if (px == p[now])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
