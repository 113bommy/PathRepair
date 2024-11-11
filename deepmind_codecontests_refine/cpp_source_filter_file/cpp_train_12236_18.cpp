#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, ans;
  cin >> n >> a >> b;
  b = b % n;
  if (b < 0) b = n + b;
  ans = (a + b) % n;
  if (ans == 0) ans = 1;
  cout << ans << endl;
}
