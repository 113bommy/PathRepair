#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    double ans = 1 / tan(3.14159265358979323846 / (2 * n));
    cout.precision(8);
    cout << fixed << ans << endl;
  }
}
