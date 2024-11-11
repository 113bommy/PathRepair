#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c;
  cin >> n >> k >> c;
  int a[c];
  for (int i = 0; i < c; i++) {
    cin >> a[i];
  }
  int src = 0, ans = 0, j = 0;
  for (int i = 1; i <= n; i++) {
    if (i == a[j] && j < c) {
      ans++;
      src = i;
      j++;
      continue;
    }
    if ((i + src) % k == 0) {
      ans++;
    }
  }
  cout << ans;
}
