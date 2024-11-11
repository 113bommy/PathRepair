#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n = 1e9;
void solve() {
  cout << "? 1 1" << endl;
  int k1, k2;
  cin >> k1;
  int l = 1, r = n;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    cout << "? " << mid << " 1" << endl;
    cin >> k2;
    if (k1 - k2 != mid - 1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << "? " << n << " 1" << endl;
  cin >> k2;
  int x1 = l, y1 = k1 + 2 - x1;
  int x2 = n + y1 - 1 - k2;
  cout << "? " << n << " " << n << endl;
  int k3;
  cin >> k3;
  int y2 = 2 * n - x2 - k3;
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
