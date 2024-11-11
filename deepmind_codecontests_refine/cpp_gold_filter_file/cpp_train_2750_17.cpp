#include <bits/stdc++.h>
using namespace std;
int n, t[1005], l, ans, maxn = -1;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l;
    t[l]++;
  }
  for (int i = 1; i <= 1000; i++) {
    if (t[i] > maxn) {
      maxn = t[i];
    }
    if (t[i]) {
      ans++;
    }
  }
  cout << maxn << ' ' << ans;
  return 0;
}
