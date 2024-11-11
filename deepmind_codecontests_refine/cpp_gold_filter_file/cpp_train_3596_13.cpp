#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a, ans = 0;
  cin >> n >> x;
  char c;
  while (n--) {
    cin >> c;
    cin >> a;
    if (c == '+')
      x = x + a;
    else if (c == '-') {
      if (a <= x)
        x = x - a;
      else
        ans++;
    }
  }
  cout << x << " " << ans << endl;
  return 0;
}
