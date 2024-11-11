#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int H, n, a[200010], i, sum = 0, f = 0, x, ans, mn;
  double s;
  cin >> H >> n;
  vector<int> v;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  x = H;
  for (i = 0; i < n; i++) {
    x += a[i];
    if (x <= 0) {
      f = 1;
      ans = i;
      break;
    }
  }
  if (f == 1)
    cout << i + 1 << endl;
  else {
    for (i = 0; i < n; i++) {
      sum += a[i];
    }
    if (sum >= 0)
      cout << "-1" << endl;
    else {
      f = 0;
      mn = a[0];
      for (i = 1; i < n; i++) {
        a[i] = a[i] + a[i - 1];
        mn = min(a[i], mn);
      }
      x = H - abs(mn);
      s = ceil((double)x / double(abs(sum)));
      ans = (int)s * n;
      H = (abs(sum) * s) - H;
      H = abs(H);
      for (i = 0; i < n; i++) {
        H += v[i];
        ans++;
        if (H <= 0) {
          f = 1;
          break;
        }
      }
      if (f == 0)
        cout << "-1" << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
