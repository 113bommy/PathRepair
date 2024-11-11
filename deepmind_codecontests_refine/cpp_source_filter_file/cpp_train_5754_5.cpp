#include <bits/stdc++.h>
using namespace std;
long long t, n, k, z, a[100005], s[100005];
struct node {
  long long val;
  long long need;
} b[100005];
bool cmp(node x, node y) { return x.val > y.val; }
signed main() {
  cin >> t;
  while (t--) {
    long long ans = 0;
    cin >> n >> k >> z;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }
    for (long long i = 1; i <= k; i++) {
      b[i].val = a[i] + a[i + 1];
      b[i].need = i;
    }
    sort(b + 1, b + k + 1, cmp);
    for (long long i = 1; i <= k; i++) {
      long long sum = s[b[i].need + 1];
      if (k - b[i].need <= z * 2)
        sum += (k - b[i].need) / 2 * b[i].val +
               (k - b[i].need - (k - b[i].need) / 2 * 2) * a[b[i].need];
      else
        sum = s[k - z * 2] + z * b[i].val;
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
}
