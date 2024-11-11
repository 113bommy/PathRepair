#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const double pi = acos(-1.0);
int main() {
  int bb, g, ans = 0;
  vector<int> a(102, 0), b(102, 0);
  cin >> bb;
  for (int i = 0; i < (bb); i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  cin >> g;
  for (int i = 0; i < (g); i++) {
    int x;
    cin >> x;
    b[x]++;
  }
  for (int i = 1; i < 101; i++) {
    if (a[i - 1] >= 0 && b[i] >= 0) {
      int x = min(a[i - 1], b[i]);
      ans += x;
      a[i - 1] -= x;
      b[i] -= x;
    }
    if (b[i - 1] >= 0 && a[i] >= 0) {
      int x = min(a[i - 1], b[i]);
      ans += x;
      b[i - 1] -= x;
      a[i] -= x;
    }
    if (a[i] >= 0 && b[i] >= 0) {
      int x = min(a[i], b[i]);
      ans += x;
      a[i] -= x;
      b[i] -= x;
    }
    if (a[i + 1] >= 0 && b[i] >= 0) {
      int x = min(a[i + 1], b[i]);
      ans += x;
      a[i + 1] -= x;
      b[i] -= x;
    }
    if (b[i + 1] >= 0 && a[i] >= 0) {
      int x = min(a[i + 1], b[i]);
      ans += x;
      b[i + 1] -= x;
      a[i] -= x;
    }
  }
  cout << ans << "\n";
  return 0;
}
