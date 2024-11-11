#include <bits/stdc++.h>
const double eps = 1e-8;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 5e4 + 10;
using namespace std;
int a[maxn];
int main() {
  int ncase;
  cin >> ncase;
  while (ncase--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int f = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] >= a[i - 1]) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      sort(a + 1, a + 1 + n);
      if (a[1] == a[n]) f = 1;
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
