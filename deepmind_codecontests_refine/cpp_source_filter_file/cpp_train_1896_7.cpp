#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
    if (a[i] < 14) {
      cout << "NO\n";
      continue;
    }
    if (a[i] % 14 > 0 && a[i] % 14 < 7) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
