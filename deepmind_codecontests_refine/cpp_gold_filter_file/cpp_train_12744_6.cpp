#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int mat[N][N];
int gash[N];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  char tmp;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      cin >> tmp;
      if (tmp - '0' == 1)
        cnt++;
      else
        cnt = 0;
      mat[i][j] = cnt;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    memset(gash, 0, sizeof(gash));
    for (int j = 1; j <= n; j++) gash[mat[j][i]]++;
    int now = m;
    int len = 0;
    while (1) {
      if (gash[now]) {
        len += gash[now];
        ans = max(ans, now * len);
        now--;
      } else {
        now--;
      }
      if (now == 0 || len > n) break;
    }
  }
  cout << ans << endl;
  return 0;
}
