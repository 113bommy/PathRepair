#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int s = 0;
    int ans = 0;
    int sum[maxn];
    int ctime = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      sum[i] = s;
      if (s > 710) {
        ans = i;
        break;
      }
      if (sum[i] > 350) {
        ctime += sum[i] - 350;
      }
    }
    cout << ans << " " << ctime << endl;
  }
  return 0;
}
