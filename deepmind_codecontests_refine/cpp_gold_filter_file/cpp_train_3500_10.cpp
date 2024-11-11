#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
int a[100500];
int d[100500];
int rd[100500];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int mx = -1e9;
  int mn = 1e9;
  d[0] = 1e9;
  d[n + 1] = 1e9;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
    d[i] = min(d[i - 1], a[i]);
  }
  for (int i = n; i >= 1; --i) {
    rd[i] = min(d[i + 1], a[i]);
  }
  if (k >= 3)
    cout << mx;
  else if (k == 2) {
    int mx = -1e9;
    for (int i = 1, res = 1e9; i < n; ++i) {
      mx = max(max(d[i], rd[i + 1]), mx);
    }
    cout << mx;
  } else if (k == 1)
    cout << mn;
  return 0;
}
