#include <bits/stdc++.h>
using namespace std;
string ask(int l1, int r1, int l2, int r2) {
  cout << "? " << r1 - l1 + 1 << ' ' << r2 - l2 + 1 << endl;
  for (int i = l1; i <= r1; ++i) cout << i << ' ';
  cout << endl;
  for (int i = l2; i <= r2; ++i) cout << i << ' ';
  cout << endl;
  string second;
  cin >> second;
  return second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
    bool ans = 0;
    for (int i = 0; i < 2 && !ans; ++i) {
      int x = rnd() % (n - 1) + 2;
      string second = ask(1, 1, x, x);
      if (second == "SECOND") {
        cout << "! 1" << endl;
        ans = 1;
      }
    }
    if (ans) continue;
    k = 1;
    int l = 1, r = 1;
    for (int i = 0; i < 10; ++i) {
      r = min(2 * k, n);
      string second = ask(1, r - k, k + 1, r);
      if (second == "FIRST") {
        l = k + 1;
        break;
      }
      k <<= 1;
      if (r == n) break;
    }
    while (l < r) {
      int m = (l + r) >> 1;
      string second = ask(1, m - l + 1, l, m);
      second == "FIRST" ? r = m : l = m + 1;
    }
    cout << "! " << l << endl;
  }
}
