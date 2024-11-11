#include <bits/stdc++.h>
using namespace std;
const int mod1 = 1000000007;
const int mod2 = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(7);
  for (int i = 0; i < 7; i++) cin >> a[i];
  int i = 0;
  while (n > 0) {
    n -= a[i];
    i = (i + 1) % 7;
  }
  cout << (i - 1 + 7) % 7 + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
