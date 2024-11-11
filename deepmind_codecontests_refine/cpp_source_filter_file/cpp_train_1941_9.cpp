#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = (long long)1505;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
int a[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int m;
  cin >> m;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < n; ++j) cnt += a[i] > a[j];
  bool flag = (cnt & 1);
  while (m--) {
    int l, r;
    cin >> l >> r;
    int t = r - l + 1;
    if ((t * (t - 1) / 2) & 1) flag = !flag;
    if (!flag)
      cout << "odd\n";
    else
      cout << "even\n";
  }
  return 0;
}
