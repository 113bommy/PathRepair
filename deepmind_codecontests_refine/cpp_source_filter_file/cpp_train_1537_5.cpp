#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int pre[N][N], last[N][N];
char s[N][N];
int n, m, x;
bool isok(int d) {
  int x;
  for (int i = 1; i <= m; i++) {
    x = pre[d - 1][i] + last[d + 1][i];
    if (!x) return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1')
        pre[i][j] = pre[i - 1][j] + 1;
      else
        pre[i][j] = pre[i - 1][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1')
        last[i][j] = last[i - 1][j] + 1;
      else
        last[i][j] = last[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (isok(i)) {
      ans = 1;
      break;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
