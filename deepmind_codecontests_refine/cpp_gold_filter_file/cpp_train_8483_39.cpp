#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ans = min(a, b), sum = 0;
  a -= ans;
  b -= ans;
  if (a) {
    sum += a / 2;
  }
  if (b) {
    sum += b / 2;
  }
  cout << ans << " " << sum << endl;
  return 0;
}
