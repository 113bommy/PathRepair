#include <bits/stdc++.h>
using namespace std;
const int mxN = 3e5 + 5;
void solve() {
  int n, q;
  cin >> n >> q;
  long long add[mxN], subs[mxN];
  for (int i = 1; i <= n; ++i) {
    add[i] = 0;
    subs[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    add[i] = max(add[i - 1], subs[i - 1] + a);
    subs[i] = max(subs[i - 1], add[i - 1] - a);
  }
  cout << max(add[n], subs[n]) << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
