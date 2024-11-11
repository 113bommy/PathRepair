#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, sum = 0;
  cin >> n >> m;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    cin >> b[i];
    b[i] = a[i] - b[i];
  }
  sort(b, b + n);
  reverse(b, b + n);
  long long int dif = sum - m;
  if (dif <= 0)
    cout << "0";
  else {
    long long int ans = 0, check = 0, fl = 0;
    for (long long int i = 0; i < n; i++) {
      check += b[i];
      if (check >= dif) {
        fl = 1;
        ans = i + 1;
        break;
      }
    }
    if (fl)
      cout << ans;
    else
      cout << "-1";
  }
  return 0;
}
