#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX_N = int(1e5) + 10;
int a[MAX_N];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int pw = 1;
    while (i + (pw << 1) < n) pw <<= 1;
    ans += a[i];
    a[i + pw] += a[i];
    a[i] = 0;
    cout << ans << endl;
  }
  return 0;
}
