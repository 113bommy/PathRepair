#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n + 2];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    for (long long int i = 1; i <= n; i++) {
      cout << -a[i + 1] << ' ' << a[i] << ' ';
      i++;
    }
    cout << '\n';
    return;
  }
  if ((a[1] + a[2]) != 0) {
    cout << a[3] << ' ' << a[3] << ' ' << -(a[1] + a[2]) << ' ';
  } else if (a[1] + a[3] != 0) {
    cout << a[2] << ' ' << -(a[1] + a[3]) << ' ' << a[2] << ' ';
  } else {
    cout << -(a[2] + a[3]) << ' ' << a[1] << ' ' << a[1] << ' ';
  }
  for (long long int i = 4; i <= n; i++) {
    cout << -a[i + 1] << ' ' << a[i] << ' ';
    i++;
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
