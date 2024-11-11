#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int c = 0;
  int ans = 0;
  if (a + b > n) c = n - a - b;
  if (a + b < n) ans = b + 1;
  if (a + b == n) ans = b;
  if (a + b > n) ans = b - c;
  if (ans < 0) ans = 0;
  cout << ans << endl;
}
