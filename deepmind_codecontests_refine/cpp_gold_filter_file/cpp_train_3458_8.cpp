#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
const int mod = 998244353;
int c[N], cc[N];
vector<int> a[N], b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) a[i].push_back(0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      b[i].push_back(j + (i - 1) * m);
      cin >> x;
      a[i].push_back(x);
    }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    for (int i = 0; i <= n; i++) c[i] = -1, cc[i] = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] % m == j % m) {
        int x = a[i][j];
        if ((x - j) / m + 1 > n) continue;
        c[i] = (i - (x - j) / m - 1 + n) % n;
        cc[c[i]]++;
      }
    }
    int tmp = n;
    for (int i = 1; i <= n; i++) {
      if (c[i] != -1) tmp = min(tmp, c[i] + (n - cc[c[i]]));
    }
    ans += tmp;
  }
  cout << ans << endl;
}
