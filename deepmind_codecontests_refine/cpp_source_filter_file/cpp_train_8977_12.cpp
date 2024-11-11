#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int mx_pos;
    for (long long i = 63; i >= 0; i--)
      if (n & (1 << i)) {
        mx_pos = i;
        break;
      }
    long long curr = 1, ans = 0;
    for (int i = 0; i <= mx_pos; i++) {
      ans += (n + 1) % curr == 0 ? (n + 1) / curr - 1 : (n + 1) / curr;
      curr *= 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
