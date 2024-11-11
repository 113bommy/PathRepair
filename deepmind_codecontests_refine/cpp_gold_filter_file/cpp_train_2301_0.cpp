#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int mod = 2e9 + 9;
int a[N], dp[N], d[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int n, k, typ = 0, mx = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (a[x] == 0) {
      typ++;
    }
    a[x]++;
    mx = max(mx, a[x]);
  }
  int kol = 0;
  if (mx >= k) {
    kol = mx / k;
    mx -= k * (mx / k);
  }
  if (mx > 0) {
    kol++;
  }
  cout << typ * kol * k - n;
  return 0;
}
