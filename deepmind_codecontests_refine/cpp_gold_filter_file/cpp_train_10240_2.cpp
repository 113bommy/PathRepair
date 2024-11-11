#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
long long z[100005];
long long ans[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) z[i + 1] = z[i] + a[i];
  for (int k = 1; k <= 100000; k++) {
    long long sz = 1, cost = 0;
    long long reach = 0, step = 0;
    while (reach < n) {
      long long f = z[min<long long>(n, reach + sz)] - z[reach];
      cost += step * f;
      step++;
      reach += sz;
      sz *= k;
    }
    ans[k] = cost;
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << ' ';
  }
  cout << '\n';
}
