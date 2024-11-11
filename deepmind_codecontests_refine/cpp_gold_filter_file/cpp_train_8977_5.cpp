#include <bits/stdc++.h>
using namespace std;
long long a[100];
void init() {
  a[0] = 1;
  for (int i = 1; i <= 62; i++) {
    a[i] = a[i - 1] * 2 + 1;
  }
}
int main() {
  int t;
  init();
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    for (long long i = 62; i >= 0; i--) {
      if (n & (1ll << i)) ans += a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
