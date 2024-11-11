#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (k == 1) {
    cout << "YES\n" << n;
    return 0;
  }
  if (sum % k != 0) {
    cout << "NO\n";
    return 0;
  } else {
    long long x = sum / k, y = 0, cnt = 0;
    vector<long long> b;
    for (long long i = 0; i < n; i++) {
      y += a[i];
      cnt++;
      if (y == x) {
        b.push_back(cnt);
        y = 0;
        cnt = 0;
      }
      if (y > x) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    for (long long i = 0; i < b.size(); i++) cout << b[i] << " ";
  }
  return 0;
}
