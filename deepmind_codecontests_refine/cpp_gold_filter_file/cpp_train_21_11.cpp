#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, l, r;
    cin >> n >> l >> r;
    bool f = 0;
    if (r == (n * (n - 1) + 1)) {
      r--;
      f = 1;
    }
    long long ans1 = (n - 1) * 2;
    long long sum = ans1, pos = 0;
    for (long long i = 1; i < n; i++) {
      if (l <= ans1) {
        pos = i;
        break;
      }
      l -= ans1;
      r -= ans1;
      ans1 -= 2;
    }
    long long pos2 = (l + 1) / 2 + pos;
    while (l <= r) {
      if (l % 2 == 0) {
        cout << pos2 << " ";
        pos2++;
      } else
        cout << pos << " ";
      if (pos2 == n + 1) {
        pos++;
        pos2 = pos + 1;
      }
      l++;
    }
    if (f == 1) cout << 1 << " ";
    cout << endl;
  }
  return 0;
}
