#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ans;
  cin >> n >> a >> b;
  if (n == 1)
    cout << "1" << endl;
  else {
    ans = (a + b + n) % n;
    if (ans == 0) ans = n;
    cout << ans << endl;
  }
  return 0;
}
