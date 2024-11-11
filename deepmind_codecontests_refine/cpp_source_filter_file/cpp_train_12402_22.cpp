#include <bits/stdc++.h>
using namespace std;
const int maxn = 222222;
int a[maxn];
int b[33];
int n;
void solve() {
  int xor_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    xor_sum ^= a[i];
  }
  if (xor_sum == 0) {
    puts("-1");
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 20; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        if (!b[j]) {
          for (int k = 0; k < j; k++) {
            if (a[i] & (1 << k)) a[i] ^= b[k];
          }
          for (int k = j + 1; k <= 20; k++) {
            if (b[k] & (1 << j)) b[k] ^= a[i];
          }
          b[j] = a[i];
          ans++;
          break;
        } else {
          a[i] ^= b[j];
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  while (cin >> n) solve();
  return 0;
}
