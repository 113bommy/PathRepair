#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize(2)
const double eps = 1e-10;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }
using namespace std;
int a[maxn], b[maxn], cnt;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cnt = n;
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    while (l < r) {
      b[cnt--] = a[l];
      l++;
      b[cnt--] = a[r];
      r--;
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}
