#include <bits/stdc++.h>
using namespace std;
int t, a, b;
inline void solve() {
  cin >> t;
  for (int i = 0; i < (t); i++) {
    cin >> a >> b;
    if (a == b) {
      cout << 0;
      continue;
    }
    if (a < b) {
      if ((b - a) % 2 == 0)
        cout << 2;
      else
        cout << 1;
    } else {
      if ((a - b) % 2 == 0)
        cout << 1;
      else
        cout << 2;
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
