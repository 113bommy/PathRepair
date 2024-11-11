#include <bits/stdc++.h>
using ld = long double;
using ll = long long int;
using ull = unsigned long long;
using namespace std;
void solve() {
  int n, d;
  cin >> n >> d;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int j, f, ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      f = a[i] + 1;
      int c = ((f - a[i + 1]) / d);
      if ((f - a[i + 1]) % d != 0) c++;
      ans += c;
      a[i + 1] += c;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
