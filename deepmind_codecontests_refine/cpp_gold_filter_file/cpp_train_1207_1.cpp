#include <bits/stdc++.h>
using namespace std;
long long int n, k, sum, a[1010];
int main() {
  while (~scanf("%lld%lld", &n, &k)) {
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      if (k * 2 >= a[i]) {
        k = max(k, a[i]);
        continue;
      } else {
        k *= 2;
        ans++;
        i--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
