#include <bits/stdc++.h>
using namespace std;
string s;
int pd[150];
int ask(int l, int r, int L, int R) {
  cout << "? " << r - l + 1 << ' ' << R - L + 1 << '\n';
  for (int i = l; i <= r; ++i) cout << i << ' ';
  cout << '\n';
  for (int i = L; i <= R; ++i) cout << i << ' ';
  cout << endl;
  cin >> s;
  return pd[s[0]];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  pd['F'] = 1, pd['S'] = 2, pd['E'] = 3, pd['W'] = 4;
  while (T--) {
    int n, k, flag = 0;
    cin >> n >> k;
    for (int i = 1; i <= 25; ++i) {
      int x = rand() % (n - 1) + 2;
      if (ask(1, 1, x, x) == 2) {
        cout << "! 1" << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      int i;
      for (i = 1; (i << 1) <= n; i <<= 1)
        if (ask(1, i, i + 1, i << 1) == 3) break;
      int l = i + 1, r = min(i << 1, n);
      while (l < r) {
        int mid = (l + r) >> 1;
        if (ask(l, mid, 1, mid - l + 1))
          l = mid + 1;
        else
          r = mid;
      }
      cout << "! " << l << endl;
    }
  }
  return 0;
}
