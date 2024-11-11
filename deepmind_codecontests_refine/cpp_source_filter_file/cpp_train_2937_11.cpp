#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int r;
  cin >> r;
  int c;
  cin >> c;
  if (c == 1) {
    if (r == 1)
      cout << "-1"
           << "\n";
    else {
      while (r--) {
        cout << ++c << "\n";
      }
    }
  } else {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << (i + 1) * (j + 1 + r) << " ";
      }
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
