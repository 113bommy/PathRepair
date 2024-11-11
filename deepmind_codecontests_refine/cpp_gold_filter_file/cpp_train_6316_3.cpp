#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int mod = 998244353;
int m, n, k = 0, flag = 0, cnt = 0;
int a[N], ans[N];
long long pow2[N];
bool did[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  ;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= k && !flag) {
      cnt++;
      did[i] = 1;
    }
    if (a[i] > k) flag = 1;
  }
  flag = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= k && !flag && !did[i]) cnt++;
    if (a[i] > k) flag = 1;
  }
  cout << cnt << endl;
}
