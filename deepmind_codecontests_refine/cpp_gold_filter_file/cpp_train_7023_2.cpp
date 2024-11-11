#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
char a[N][N];
int n, m, ans, used[N], pred[N], nxt[N];
void f(int first) {
  for (int i = 0; i < m; i++)
    if (a[first][i] > a[first + 1][i]) {
      used[i] = 1;
    }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      nxt[j] = j + 1;
      pred[j] = j - 1;
    }
    nxt[0] = 1;
    pred[m + 1] = m;
    nxt[m] = m + 1;
  }
  while (1) {
    bool p = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j != m + 1; j = nxt[j]) {
        if (a[i][j] > a[i + 1][j]) {
          ans++;
          p = 1;
          nxt[pred[j]] = nxt[j];
          pred[nxt[j]] = pred[j];
        } else if (a[i][j] < a[i + 1][j])
          break;
      }
    }
    if (!p) break;
  }
  cout << ans;
}
