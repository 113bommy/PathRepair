#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
using namespace std;
int a[N], ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, k, len = 0, sum = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % k)
    cout << "NO" << endl;
  else {
    int v = sum / k, cnt = 0;
    sum = 0;
    for (i = 1; i <= n; i++) {
      cnt++;
      sum += a[i];
      if (sum > v) {
        cout << "No" << endl;
        return 0;
      }
      if (sum == v) {
        ans[++len] = cnt;
        cnt = 0;
        sum = 0;
      }
    }
    cout << "Yes" << endl;
    for (i = 1; i <= len; i++) cout << ans[i] << " ";
  }
  return 0;
}
