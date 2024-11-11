#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int n, m;
int a[maxn][maxn], b[maxn][maxn];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      a[i][j] ^= b[i][j];
    }
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    int tm = 0;
    for (int j = 1; j <= m; j++) {
      tm += a[i][j];
    }
    if (tm % 2) flag = 1;
  }
  for (int i = 1; i <= n; i++) {
    int tm = 0;
    for (int j = 1; j <= m; j++) {
      tm += a[j][i];
    }
    if (tm % 2) flag = 1;
  }
  if (flag)
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}
