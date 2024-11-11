#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
void Solve() {
  int l, r;
  cin >> l >> r;
  if (r - l < 2) {
    cout << -1;
    return;
  }
  if (r - l == 2 && l % 2 != 0) {
    cout << -1;
    return;
  }
  if (l % 2 == 0)
    cout << l << " " << l + 1 << " " << l + 2;
  else
    cout << l + 1 << " " << l + 2 << " " << l + 3;
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
}
