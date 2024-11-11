#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
int n;
int p[N], a[N];
int f[N][2], pre[N][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    f[1][0] = f[1][1] = -INF;
    for (int i = 2; i <= n; i++) {
      f[i][0] = f[i][1] = INF;
      if (p[i] > f[i - 1][0]) {
        if (f[i][0] > p[i - 1]) {
          f[i][0] = p[i - 1];
          pre[i][0] = 0;
        }
      }
      if (p[i] > p[i - 1]) {
        if (f[i][0] > f[i - 1][0]) {
          f[i][0] = f[i - 1][0];
          pre[i][0] = 0;
        }
      }
      if (p[i] > f[i - 1][1]) {
        if (f[i][0] > -p[i - 1]) {
          f[i][0] = -p[i - 1];
          pre[i][0] = 1;
        }
      }
      if (p[i] > -p[i - 1]) {
        if (f[i][0] > f[i - 1][1]) {
          f[i][0] = f[i - 1][1];
          pre[i][0] = 1;
        }
      }
      if (-p[i] > f[i - 1][0]) {
        if (f[i][1] > p[i - 1]) {
          f[i][1] = p[i - 1];
          pre[i][1] = 0;
        }
      }
      if (-p[i] > p[i - 1]) {
        if (f[i][1] > f[i - 1][0]) {
          f[i][1] = f[i - 1][0];
          pre[i][1] = 0;
        }
      }
      if (-p[i] > f[i - 1][1]) {
        if (f[i][1] > -p[i - 1]) {
          f[i][1] = -p[i - 1];
          pre[i][1] = 1;
        }
      }
      if (-p[i] > -p[i - 1]) {
        if (f[i][1] > f[i - 1][1]) {
          f[i][1] = f[i - 1][1];
          pre[i][1] = 1;
        }
      }
    }
    if (f[n][0] == INF && f[n][1] == INF)
      cout << "NO" << endl;
    else {
      int ed = f[n][0] != INF ? 0 : 1;
      for (int i = n; i >= 1; i--) {
        a[i] = ed == 0 ? p[i] : -p[i];
        ed = pre[n][ed];
      }
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) cout << a[i] << ' ';
      cout << endl;
    }
  }
  return 0;
}
