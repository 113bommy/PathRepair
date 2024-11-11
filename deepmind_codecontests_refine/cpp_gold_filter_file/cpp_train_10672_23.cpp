#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653;
const long long infi = 1000000001;
const string no = "NO\n", yes = "YES\n", nl = "\n";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  long long n, m, i, length, d, p, bank, k, j, x, y, ans, q;
  string s;
  while (t--) {
    ans = 0;
    cin >> n >> p;
    long long a[n][2];
    for (i = 0; i < n; i++) {
      cin >> x >> y;
      a[i][0] = y - x + 1;
      a[i][1] = a[i][0] - (y / p - (x - 1) / p);
    }
    long double money = 0;
    for (i = 0; i < n; i++) {
      money +=
          (a[i][1] * a[(i + 1) % n][1] * 1.0) / (a[i][0] * a[(i + 1) % n][0]);
    }
    cout << fixed << setprecision(10) << (n - money) * 2000;
  }
  return 0;
}
