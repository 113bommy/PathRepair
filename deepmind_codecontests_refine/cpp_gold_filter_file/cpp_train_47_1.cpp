#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9;
long long int fun() {
  long long int n, i, j, x, h;
  cin >> n;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long int p = a[0];
  long long int cnt = 1;
  for (long long int i = 1; i < n; i++) {
    if (a[i] - p > b[i]) {
      p = a[i];
      cnt++;
    } else if (a[i + 1] - a[i] > b[i]) {
      p = a[i] + b[i];
      cnt++;
    } else {
      p = a[i];
    }
  }
  cout << cnt;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t > 0) {
    fun();
    t--;
    cout << "\n";
  }
}
