#include <bits/stdc++.h>
using namespace std;
string s;
void solve(int l, int r) {
  if (l == r) {
    cout << "! " << l << '\n';
    return;
  }
  int mid = (l + r >> 1);
  cout << "? " << mid - l + 1 << " " << mid - l + 1 << '\n';
  for (int i = 1; i <= mid - l + 1; ++i) cout << i << " ";
  cout << "\n";
  for (int i = l; i <= mid; ++i) cout << i << " ";
  cout << '\n';
  cin >> s;
  if (s[0] == 'F')
    solve(l, mid);
  else
    solve(mid + 1, r);
}
int T, n, k, i, j, fl;
int main() {
  cin >> T;
  srand(time(NULL));
  while (T--) {
    cin >> n >> k;
    fl = 0;
    for (i = 1; i <= 30; ++i) {
      cout << "? 1 1\n" << 1 << '\n' << rand() % (n - 1) + 2 << "\n";
      cin >> s;
      if (s[0] == 'S') {
        cout << "2\n";
        fl = 1;
        break;
      }
    }
    if (fl) continue;
    for (i = 1; (1 << i) <= n; ++i) {
      cout << "? " << (1 << i - 1) << " " << (1 << i - 1) << '\n';
      for (j = 1; j <= (1 << i - 1); ++j) cout << j << " ";
      cout << "\n";
      for (j = 1; j <= (1 << i - 1); ++j) cout << j + (1 << i - 1) << " ";
      cout << "\n";
      cin >> s;
      if (s[0] == 'F') {
        solve((1 << i - 1) + 1, 1 << i);
        fl = 1;
        break;
      }
    }
    if (fl) continue;
    solve((1 << i - 1) + 1, n);
  }
}
