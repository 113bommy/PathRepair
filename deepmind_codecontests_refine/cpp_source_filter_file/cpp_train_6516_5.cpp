#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string second = "abc";
void solve() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << second[i % 3];
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
