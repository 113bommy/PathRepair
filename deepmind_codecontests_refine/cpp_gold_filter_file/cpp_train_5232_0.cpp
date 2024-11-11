#include <bits/stdc++.h>
using namespace std;
long long int id[100005], a[100005], n, t, p[100005];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      id[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 2; j--) {
        if (a[j] < a[j - 1]) {
          swap(a[j], a[j - 1]);
          swap(id[j], id[j - 1]);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      p[i] = id[i];
    }
    int ans = 100000000;
    for (int i = 1; i <= n; i++) {
      int now = n, pre = -1;
      for (int j = i; j <= n; j++) {
        if (p[j] > pre) {
          now--;
          pre = p[j];
        } else
          break;
      }
      ans = min(ans, now);
    }
    cout << ans << endl;
  }
}
