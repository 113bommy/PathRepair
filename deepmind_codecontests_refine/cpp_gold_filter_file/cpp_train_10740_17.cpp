#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
void solve() {
  int b, w;
  cin >> b >> w;
  int mn = min(b, w), mx = max(b, w);
  if (mx > 3 * mn + 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (b == w) {
    for (int i = 1; i <= 2 * mn; i++) cout << 1 << ' ' << i << '\n';
    return;
  }
  if (b > w) {
    cout << "2 " << 1 << "\n";
    b--;
    int extra = b - w;
    for (int i = 2; i <= 2 * w; i += 2) {
      cout << 2 << ' ' << i << "\n";
      cout << 2 << ' ' << i + 1 << "\n";
      if (extra > 0) {
        cout << "1 " << i << "\n";
        extra--;
      }
      if (extra > 0) {
        cout << "3 " << i << "\n";
        extra--;
      }
    }
  } else {
    cout << "3 " << 1 << "\n";
    w--;
    int extra = w - b;
    for (int i = 2; i <= 2 * b; i += 2) {
      cout << 3 << ' ' << i << "\n";
      cout << 3 << ' ' << i + 1 << "\n";
      if (extra > 0) {
        extra--;
        cout << 2 << ' ' << i << "\n";
      }
      if (extra > 0) {
        extra--;
        cout << 4 << ' ' << i << "\n";
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
