#include <bits/stdc++.h>
const double esp = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int inf = 1e9;
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int m, n;
const int N = 1010;
int sumr[N][N], sumc[N][N];
char grp[N][N];
int main() {
  n = read();
  m = read();
  for (int i = 0; i < n; i++) {
    cin >> grp[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != 0)
        sumr[i][j] = grp[i][j] == grp[i][j - 1] ? sumr[i][j - 1] + 1 : 1;
      else
        sumr[i][0] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (i != 0)
        sumc[i][j] = grp[i][j] == grp[i - 1][j] ? sumc[i - 1][j] + 1 : 1;
      else
        sumc[0][j] = 1;
    }
  }
  long long ans = 0;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      int len = sumc[i][j];
      if (i - len >= 0) {
        int len2 = sumc[i - len][j];
        if (len2 != len) continue;
        if (i - len - len2 >= 0) {
          int len3 = sumc[i - len - len2][j];
          if (len3 < len2) continue;
          int st = i - len - len2 - len2 + 1;
          int minn = inf;
          for (int k = st; k <= i; k++) {
            minn = min(sumr[k][j], minn);
          }
          ans += minn;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
