#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, tmp;
  cin >> n;
  vector<int> a(n);
  bool ok = true;
  int cur = 1;
  for (int i = 0; i < 2 * n; ++i) {
    if (!ok && cur >= n) {
      break;
    }
    if (ok && cur >= n) {
      a[n - 1] = 1;
      cur = 1;
      ok = false;
    }
    if (ok) {
      cout << "? ";
      for (int i = 0; i < n - 1; ++i) {
        cout << 1 << ' ';
      }
      cout << 1 + cur << endl;
      cin >> tmp;
      if (tmp == 0) {
        a[n - 1] = n - i;
        cur = 1;
        ok = false;
        continue;
      } else {
        a[tmp - 1] = cur;
      }
    } else {
      cout << "? ";
      for (int i = 0; i < n - 1; ++i) {
        cout << 1 + cur << ' ';
      }
      cout << 1 << endl;
      cin >> tmp;
      if (tmp != 0) {
        a[tmp - 1] = -cur;
      }
    }
    ++cur;
  }
  cout << "! ";
  for (int i = 0; i < n - 1; ++i) {
    cout << a[n - 1] + a[i] << ' ';
  }
  cout << a[n - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
