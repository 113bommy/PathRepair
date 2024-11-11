#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 20;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
int n, m;
int a[N];
int b[N];
int x, y;
int i, j;
int cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> x;
  for (i = 2; i <= n; i++) {
    cin >> a[i];
  }
  cin >> y;
  for (i = 2; i <= m; i++) {
    cin >> b[i];
  }
  i = j = 1;
  while (i <= n || j <= m) {
    x > y   ? (y += b[++j])
    : x < y ? (x += a[++i])
            : (x += a[++i], y += b[++j], cnt++);
  }
  cout << cnt;
}
