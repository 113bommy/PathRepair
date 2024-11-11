#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653;
const long long infi = 1000000001;
const long long MOD = 1000000007;
const long long mod = 998244353;
const string no = "NO\n", yes = "YES\n";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j;
  cin >> n;
  long long a[n][2];
  for (i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  long long a1[n], a2[n];
  a1[0] = a[0][0] + a[0][1];
  a2[n - 1] = a[n - 1][0] + a[n - 1][1];
  for (i = 1; i < n; i++) {
    a1[i] = min(a1[i - 1] + 1, a[i][0] + a[i][1]);
  }
  for (i = n - 1 - 1; i >= 0; i--) {
    a2[i] = min(a[i][0] + a[i][1], a2[i + 1] + 1);
  }
  long long ans = 0, t = 0, ch = 0;
  vector<long long> v;
  for (i = 0; i < n; i++) {
    t = min(a1[i], a2[i]);
    v.emplace_back(t);
  }
  for (i = 0; i < n; i++) {
    if (v[i] < a[i][0]) {
      ch = 1;
      break;
    } else {
      ans += v[i] - a[i][0];
    }
  }
  if (ch)
    cout << -1;
  else {
    cout << ans << endl;
    for (i = 0; i < n; i++) cout << v[i] << ' ';
  }
  return 0;
}
