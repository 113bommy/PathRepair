#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n < 6) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < n - 3; i++) cout << 1 << " " << i + 2 << "\n";
    cout << n - 2 << " " << n - 1 << "\n";
    cout << n - 2 << " " << n << "\n";
  }
  for (int i = 1; i < n; i++) cout << i << " " << i + 1 << "\n";
}
