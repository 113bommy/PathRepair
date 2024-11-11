#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> ans;
void solve() {
  int a, b, c;
  int n;
  cin >> n;
  a = 1, b = 1, c = n - 2;
  while (1) {
    if (c % 3 == 0) break;
    --c;
    ++b;
  }
  cout << a << " " << b << " " << c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
