#include <bits/stdc++.h>
using namespace std;
const long long MAX = 100005;
const long long MOD = 1000000007;
const double PI = 2 * acos(0.0);
const double EPS = 0.00000000001;
int main() {
  long long n, x;
  cin >> n;
  vector<long long> a;
  for (long long i = 0; i < n * 2; i++) {
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long i = 0, j = a.size() - 1, x_h = 0, x_l = MOD, y_h = 0, y_l = MOD;
  while (i < j) {
    x_h = max(a[i], x_h);
    x_l = min(a[i], x_l);
    y_h = max(a[j], y_h);
    y_l = min(a[j], y_l);
    i++, j--;
  }
  long long ans = (x_h - x_l) * (y_h - y_l);
  j = 1;
  for (long long i = n; i < a.size() - 1; i++) {
    ans = min(ans, (a[i] - a[j]) * (a[2 * n - 1] - a[0]));
    j++;
  }
  cout << ans << endl;
  return 0;
}
