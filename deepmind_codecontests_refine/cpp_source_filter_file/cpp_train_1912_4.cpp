#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
char a[100][10000];
int T[100][10000];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  memset(T, INF, sizeof T);
  for (int i = 0; i < n; i++) {
    int pos = 0;
    while (pos < m && a[i][pos] != '1') pos++;
    if (pos == m) {
      cout << "-1" << endl;
      return 0;
    }
    int det = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][(pos + j) % m] == '1')
        det = 0;
      else
        det++;
      T[i][(pos + j) % m] = det;
    }
    det = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][(m + pos - j) % m] == '1')
        det = 0;
      else
        det++;
      T[i][(m + pos - j) % m] = min(T[i][m + pos - j], det);
    }
  }
  int ans = INF;
  for (int i = 0; i < m; i++) {
    int tmp = 0;
    for (int j = 0; j < n; j++) tmp += T[j][i];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
