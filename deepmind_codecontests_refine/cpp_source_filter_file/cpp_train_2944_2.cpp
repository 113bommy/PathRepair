#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int len = 1, ans = a[1], pre = a[2];
    for (int i = 3; i <= n; ++i) {
      if (a[i] == pre)
        len++;
      else
        len = 1, pre = a[i];
      if (len == 3) ans++, len = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
