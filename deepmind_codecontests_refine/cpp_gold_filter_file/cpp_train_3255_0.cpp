#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (a[i] % b[0]) {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (int z = 0; z < t; z++) {
    solve();
  }
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
  return 0;
}
