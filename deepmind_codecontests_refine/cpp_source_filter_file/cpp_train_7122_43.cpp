#include <bits/stdc++.h>
using namespace std;
int cnt[101];
void solve() {
  int n, m, sum = 0;
  cin >> n >> m;
  int x, y, owe;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y >> owe;
    cnt[x] += owe;
    cnt[y] -= owe;
  }
  for (long long i = 0; i < m; i++) {
    if (cnt[i] >= 0) sum += cnt[i];
  }
  cout << sum << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
}
