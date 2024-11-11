#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
long long n, sum, ans;
long long a[200010];
struct BIT {
  long long tree[700010];
  BIT() { memset(tree, 0, sizeof(tree)); }
  void update(long long i, long long x) {
    while (i <= 400000) {
      tree[i] += x;
      i += i & -i;
    }
  }
  long long sum(long long i) {
    long long ret = 0;
    while (i) {
      ret += tree[i];
      i -= i & -i;
    }
    return ret;
  }
} t1, t2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ans += (i - 1) * a[i] - t1.sum(a[i]);
    long long x = sum;
    for (long long j = a[i]; j <= 300000; j += a[i]) {
      t1.update(j, a[i]);
      x -= (j / a[i]) * a[i] * (t2.sum(j + a[i] - 1) - t2.sum(j - 1));
    }
    ans += x;
    sum += a[i];
    t2.update(a[i], 1);
    cout << ans << " ";
  }
}
