#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int days = 1, prev = v0;
  while (prev < c) {
    prev = prev - l + min(v0 + (days - 1) * a, v1);
    days++;
  }
  cout << days;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
