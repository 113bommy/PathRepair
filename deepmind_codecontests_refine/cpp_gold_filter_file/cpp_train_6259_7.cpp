#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int x = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] != x) {
      if (a[i] < 30) {
        ll y = (1ll << x) - 1;
        if (y * y > (1ll << a[i]) - 1) {
          cout << "YES\n";
          return 0;
        }
      } else if (2 * x > a[i]) {
        cout << "YES\n";
        return 0;
      }
      x = a[i];
    }
  }
  cout << "NO\n";
}
