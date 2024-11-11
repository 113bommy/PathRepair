#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 123;
const int inf = 1e9 + 123;
const long long INF = 1e18;
const double eps = 1e-5;
int n, ans;
int a[N], u[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int s = 1;
  for (int i = n; i >= 2; i--) {
    if (a[i] < a[i - 1]) {
      u[i] = 1;
      swap(a[i], a[i - 1]);
      u[i] = 1;
      swap(a[i], a[i - 1]);
    }
  }
  for (int cc = 1e3; cc >= 2; cc--) {
    for (int i = n; i >= 2; i--) {
      if (a[i] < a[i - 1]) {
        if (i == 2) s = 2;
        u[i] = 1;
        swap(a[i], a[i - 1]);
      }
    }
  }
  for (int i = s; i <= n; i++) {
    if (!u[i]) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
