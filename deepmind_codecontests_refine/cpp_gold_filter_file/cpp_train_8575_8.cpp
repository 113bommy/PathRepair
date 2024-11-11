#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  char c = 'a';
  char p = 'b';
  if (k > n) {
    cout << -1;
  } else if (k == 1 && n > 1) {
    cout << -1;
  } else {
    int r = n - k + 2;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && r > 0) {
        cout << c;
        r--;
      } else {
        r--;
        if (r < 0) {
          p++;
          cout << p;
        } else {
          cout << p;
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
