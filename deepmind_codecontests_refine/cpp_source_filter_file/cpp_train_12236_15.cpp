#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, ans;
  cin >> n >> a >> b;
  if (b > 0) {
    ans = (a + b) % n;
    if (ans == 0) ans = n;
  } else if (b < 0) {
    if (a > abs(b)) {
      ans = a - abs(b);
    } else {
      ans = n - abs(a + b);
    }
  } else
    ans = a;
  cout << ans;
}
