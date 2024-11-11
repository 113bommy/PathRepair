#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
bool b[maxn];
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  memset(b, true, sizeof(b));
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      cout << -1;
      return 0;
    }
    b[x] = false;
    if (b[x - 1])
      a[x] = x - 1;
    else
      a[x] = a[x - 1];
  }
  long long ans = INF;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    int j = 0;
    long long res = 0;
    int f = 0;
    while (j < n) {
      int k = j;
      res += x;
      j += i;
      if (j < n && !b[j]) {
        j = a[j];
        if (j == k) {
          f = 1;
          break;
        }
      }
    }
    if (f == 0) ans = min(ans, res);
  }
  if (ans < INF)
    cout << ans;
  else
    cout << -1;
  return 0;
}
