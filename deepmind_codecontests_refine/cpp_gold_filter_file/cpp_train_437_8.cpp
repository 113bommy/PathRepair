#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, a;
  cin >> x;
  set<int> arr;
  while (x--) {
    cin >> a;
    arr.insert(a);
  }
  cout << arr.size() << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
