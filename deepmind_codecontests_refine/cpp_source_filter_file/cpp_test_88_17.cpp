#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<int> a;
  int p = 0, cnt = 0;
  for (auto& i : vec) {
    cin >> i;
  }
  if (n % 2 == 0) {
    cout << "YES" << '\n';
    return;
  }
  p = vec[0];
  for (int i = 1; i < n; i++) {
    if (vec[i] >= vec[i - 1]) {
      cout << "YES" << '\n';
      return;
    }
    p = i;
  }
  cout << "NO" << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
