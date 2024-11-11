#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, x = 1;
  cin >> a >> b;
  int ans = 0;
  for (long long int i = a + 1; i <= b; i++) {
    x *= i;
    x = x % 10;
    ans = x % 10;
    if (x % 10 == 0) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
