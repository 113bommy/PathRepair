#include <bits/stdc++.h>
using namespace std;
bool checkdigits(int x) {
  vector<int> cnt(10, 0);
  while (x != 0) {
    cnt[x % 10]++;
    if (cnt[x % 10] > 1) return false;
    x /= 10;
  }
  return true;
}
void solve() {
  int l, r;
  cin >> l >> r;
  for (int i = l; i < +r; i++) {
    if (checkdigits(i)) {
      cout << i;
      return;
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
}
