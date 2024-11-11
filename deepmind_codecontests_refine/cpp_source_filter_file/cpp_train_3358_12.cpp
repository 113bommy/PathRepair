#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cout << 2 << ' ';
  cout << 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
