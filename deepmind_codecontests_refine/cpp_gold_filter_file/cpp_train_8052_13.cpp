#include <bits/stdc++.h>
using namespace std;
const long double pi = atan(1) * 4;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, a, b;
  cin >> n >> x;
  bool ans = true;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == x || a == 7 - x || b == x || b == 7 - x) ans = false;
  }
  cout << (ans ? "YES" : "NO");
}
