#include <bits/stdc++.h>
using namespace ::std;
bool ar[300005];
int main() {
  int n, ans = 1;
  cin >> n;
  int t = n;
  cout << ans << ' ';
  for (int i = 0, c; i < n; i++) {
    cin >> c;
    ++ans;
    ar[c] = 1;
    if (c == t)
      while (ar[t]) --t, --ans;
    cout << ans << ' ';
  }
  cout << '\n';
}
