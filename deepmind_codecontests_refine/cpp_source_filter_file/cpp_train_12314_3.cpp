#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == v[i + 1]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    Solve();
    cout << "\n";
  }
  return 0;
}
