#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, l, d = 0, ans = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> l;
    d += l;
    if (d <= x) ans++;
  }
  cout << ans << endl;
}
