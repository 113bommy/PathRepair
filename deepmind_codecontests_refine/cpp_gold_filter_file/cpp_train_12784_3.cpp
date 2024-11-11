#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, a, t = 0, ans = 1;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a;
    t += a;
    if (t <= x) ans++;
  }
  cout << ans << endl;
}