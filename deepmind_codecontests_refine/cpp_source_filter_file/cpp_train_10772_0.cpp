#include <bits/stdc++.h>
using namespace std;
const int N = 222222;
int n, m;
char a[N], b[N], c[N], d[N];
int id1[N];
int p[30][30];
int u[40];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      ++m;
      c[m] = a[i];
      id1[m] = i;
      d[m] = b[i];
    }
  }
  for (int i = 1; i <= m; ++i) {
    p[int(c[i] - 'a' + 1)][int(d[i] - 'a' + 1)] = i;
    u[int(d[i] - 'a' + 1)] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int x = d[i] - 'a' + 1;
    int y = c[i] - 'a' + 1;
    if (p[x][y]) {
      cout << 2 << endl;
      cout << id1[i] << ' ' << id1[p[x][y]] << endl;
      return 0;
    }
  }
  for (int i = 1; i <= m; ++i) {
    int x = c[i] - 'a' + 1;
    if (u[x]) {
      cout << 1 << endl;
      cout << id1[i] << ' ' << id1[u[x]] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  cout << "-1 -1";
}
