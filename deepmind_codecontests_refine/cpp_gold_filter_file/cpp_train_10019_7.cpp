#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const long long inf = 0x3f3f3f3f;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int pos[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      pos[x] = i;
    }
    bool ok = 0;
    int l = 1, r = n, f = 0;
    for (int i = 1; i <= n; i++) {
      if (pos[i] == r) {
        if (f && pos[i] - pos[i - 1] != 1 && l != i) {
          ok = 1;
          break;
        }
        r = pos[l] - 1;
        l = i + 1;
        f = 0;
      } else {
        if (!f)
          l = i;
        else if (pos[i] - pos[i - 1] != 1) {
          ok = 1;
          break;
        }
        f = 1;
      }
    }
    if (ok)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
