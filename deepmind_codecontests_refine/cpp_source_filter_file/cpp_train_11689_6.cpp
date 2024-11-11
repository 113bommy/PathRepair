#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n;
  cin >> n;
  vector<long long int> a(3), b(3);
  for (long long int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  long long int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  long long int mn = INT_MIN;
  for (long long int i = 0; i < 3; i++) {
    mn = max(mn, a[i] - b[(i + 2) % 3] - b[i]);
  }
  cout << mn << " " << mx << endl;
  return 0;
}
