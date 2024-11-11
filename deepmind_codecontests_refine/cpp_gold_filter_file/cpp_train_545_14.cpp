#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto& c : a) cin >> c;
  if (n == 1) {
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << -a[0] << endl;
    return;
  }
  cout << 1 << " " << 1 << endl;
  cout << -a[0] << endl;
  cout << 1 << " " << n << endl;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      cout << 0 << " ";
    else
      cout << (-n) * (a[i]) << " ";
  }
  cout << endl;
  cout << 2 << " " << n << endl;
  for (int i = 1; i < n; i++) {
    cout << (n - 1) * (a[i]) << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
