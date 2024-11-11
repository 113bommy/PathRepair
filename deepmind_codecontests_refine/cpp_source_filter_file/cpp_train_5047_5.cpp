#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, ans = 0;
  cin >> a >> b;
  while (b) {
    ans += a / b;
    int c = a % b;
    a = b;
    b = c;
  }
  cout << ans << endl;
  return 0;
}
