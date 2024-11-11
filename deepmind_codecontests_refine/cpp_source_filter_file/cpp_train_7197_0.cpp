#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  int x, y;
  long long int ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x == a && y == b) continue;
    ans += max(0, min(x, y) - max(a, b) + 1);
    if (x == y) ans--;
    a = x;
    b = y;
  }
  cout << ans << endl;
}
