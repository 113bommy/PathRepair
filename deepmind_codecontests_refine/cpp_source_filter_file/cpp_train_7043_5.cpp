#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
void solve() {
  int l, w;
  cin >> l >> w;
  vector<int> a(l);
  vector<int> s(l, 0);
  int ans = 1e8;
  for (int i = 1; i < l; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < l; i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = w; i < l; i++) {
    ans = min(ans, s[i] - s[i - w]);
  }
  cout << (ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
