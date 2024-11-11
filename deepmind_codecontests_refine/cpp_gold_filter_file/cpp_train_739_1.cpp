#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  bool p = true;
  for (int x = 0; x < pow(2, n); x++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (x >> j & 1) {
        sum += a[j];
      } else
        sum -= a[j];
    }
    if (sum % 360 == 0) {
      p = false;
      break;
    }
  }
  if (p)
    cout << "NO";
  else
    cout << "YES";
}
