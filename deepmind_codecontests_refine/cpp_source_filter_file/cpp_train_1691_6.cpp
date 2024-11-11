#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int ind = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++)
    if (v[i] - v[i + 1] > 1) {
      cout << "NO\n";
      return;
    }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
