#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  int a[n], b[n];
  for (int i = 1; i < 6; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    b[x]++;
  }
  int ans = 0;
  int res = 0;
  for (int i = 1; i < 6; i++) {
    ans += abs(a[i] - b[i]) / 2;
    res += a[i] - b[i];
    if ((a[i] + b[i]) % 2 == 1) {
      cout << -1;
      return 0;
    }
  }
  if (res != 0)
    cout << -1;
  else
    cout << ans / 2;
}
