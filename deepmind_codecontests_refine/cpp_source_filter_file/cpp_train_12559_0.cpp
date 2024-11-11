#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846264338327950288419716939937510;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < (t); i++) {
    int n, l, r;
    cin >> n;
    int cur = 1;
    for (int j = 0; j < (n); j++) {
      cin >> l >> r;
      if (r >= cur) {
        cout << cur << " ";
        cur = max(l + 1, cur + 1);
      } else {
        cout << 0 << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
