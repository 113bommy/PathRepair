#include <bits/stdc++.h>
using namespace std;
long long int ok = 1000 * 1000 * 1000 + 7;
long long int w, b;
void convert(long long int x, long long int y, long long int mini) {
  long long int t = abs(b - w);
  long long int a = t - 1;
  cout << x << " " << y << "\n";
  x++;
  long long int z = 0;
  while (mini > 0) {
    cout << x << " " << y << "\n";
    if (z % 2 == 0) {
      mini--;
      if (a > 0) {
        cout << x << " " << y - 1 << "\n";
        a--;
      }
      if (a > 0) {
        cout << x << " " << y + 1 << "\n";
        a--;
      }
    }
    z++;
    x++;
  }
  if (w != b) cout << x << " " << y << "\n";
}
void solve() {
  cin >> b >> w;
  if (abs(b - w) > (min(b, w) * 3) + 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (b > w) {
    convert(1, 2, w);
  } else {
    convert(1, 3, b);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
