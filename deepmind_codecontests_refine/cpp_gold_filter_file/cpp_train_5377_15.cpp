#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      ans++;
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
}
