#include <bits/stdc++.h>
using namespace std;
int a[15];
long long pow10(int x) {
  long long ans = 1;
  for (int i = 1; i <= x; i++) ans *= 10;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    a[n + 1] = 18;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      int x = min((long long)k + 1, pow10(a[i + 1] - a[i]) - 1);
      ans += x * pow10(a[i]);
      k -= x;
    }
    cout << ans << endl;
  }
  return 0;
}
