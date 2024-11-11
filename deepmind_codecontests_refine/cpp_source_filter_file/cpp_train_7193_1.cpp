#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int maxn = 100005;
const int inf = 1e9;
using std::cin;
using std::cout;
int n, w, q;
int a[maxn];
int ask[maxn];
int min[maxn];
int max[maxn];
int ans[maxn];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n >> w >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    cin >> ask[i], ask[i] = w - ask[i];
    ;
    min[i] = max[i] = a[0];
  }
  for (int i = 0; i < n; ++i) {
    const int v = a[i];
    for (int i = 0; i < q; ++i) {
      if (min[i] > v) min[i] = v;
      if (max[i] < v) max[i] = v;
      if (max[i] - min[i] > ask[i]) {
        ans[i] += 1;
        min[i] = v;
        max[i] = v;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] - 1 << '\n';
  }
}
