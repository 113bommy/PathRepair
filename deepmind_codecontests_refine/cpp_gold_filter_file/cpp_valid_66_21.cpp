#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i < 1e9; ++i) {
      if (i % 3 == 0 || i % 10 == 3) continue;
      if (--n == 0) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
