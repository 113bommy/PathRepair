#include <bits/stdc++.h>
using namespace std;
vector<int> d(1000001);
void solve() {
  int n;
  cin >> n;
  cout << d[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cur = 1;
  for (int i = 1; i <= 1e6; ++i) {
    d[i] = cur;
    if (i % 2 == 0) ++cur;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
}
