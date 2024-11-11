#include <bits/stdc++.h>
using namespace std;
int n;
int bit[2010000];
void add(long long a, long long w) {
  a++;
  for (int x = a; x <= n + 1; x += (x & (-x))) {
    bit[x] += w;
  }
}
int sum(int a) {
  int ret = 0;
  for (int x = a; x > 0; x -= (x & (-x))) {
    ret += bit[x];
  }
  return ret;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  cin >> n;
  int c[n];
  array<int, 2> a[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i] = {c[i], -i};
  }
  sort(a, a + n, greater<array<int, 2>>());
  int q;
  cin >> q;
  array<int, 3> p[q];
  int ans[q];
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y, i};
  }
  sort(p, p + q);
  int now = 0;
  for (int i = 0; i < q; i++) {
    while (now < p[i][0]) {
      add(-a[now][1], 1);
      now++;
    }
    int low = -1, up = n, mid;
    while (up - low > 1) {
      mid = (up + low) / 2;
      int ret = sum(mid + 1);
      if (ret >= p[i][1])
        up = mid;
      else
        low = mid;
    }
    ans[p[i][2]] = c[up];
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}
