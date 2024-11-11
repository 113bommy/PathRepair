#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int len = n + 1;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    len = min(len, r - l + 1);
  }
  int curr = 0;
  cout << len << "\n";
  for (int i = 0; i < n; i++) {
    cout << curr << " ";
    curr = (curr + 1) % len;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
