#include <bits/stdc++.h>
using namespace std;
long long n;
long long a, b, c, d, x, y, z, l, t;
long long arr[3000000];
void in() {
  cin >> n >> l >> t;
  long double ans = 0.0;
  a = t / l;
  t = t % l;
  ans += (a * (n) * (n - 1) / 4.0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n; i < 2 * n; i++) {
    arr[i] = arr[i - n] + l;
  }
  for (int i = 0; i < n; i++) {
    b = upper_bound(arr, arr + 2 * n, arr[i] + 2 * t) - (arr + i);
    b--;
    ans += (b / 4.0);
  }
  cout << ans << endl;
}
void solve() {}
int main() {
  cout << setprecision(20);
  in();
  solve();
}
