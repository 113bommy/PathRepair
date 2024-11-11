#include <bits/stdc++.h>
using namespace std;
void f(int n) {
  for (int i = 0; i < 6; i++) {
    cout << ((n & (1 << i)) >> i);
  }
  cout << "\n";
}
int bit(int n, int i) { return ((n & (1 << i)) >> i); }
void Solve() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a = {4, 1, 3, 0, 2, 5};
  for (int i = 0; i <= 5; i++) {
    ans += bit(n, i) << a[i];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
