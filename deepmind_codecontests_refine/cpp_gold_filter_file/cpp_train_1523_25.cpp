#include <bits/stdc++.h>
using namespace std;
int col[5001], x[5001], y[5001], n;
int dis[5001][5001];
int h, t, m;
long long ans = 1LL;
int s;
bool judge(int X, int Col) {
  if (col[X] != 0) return col[X] == Col;
  col[X] = Col;
  for (int i = 1; i <= n; i++) {
    if (i != X && m < dis[X][i] && !judge(i, -Col)) return false;
  }
  return true;
}
bool Judge() {
  for (int i = 1; i <= n; i++) col[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (!col[i]) {
      if (!judge(i, 1)) return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dis[i][j] = dis[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
  }
  h = 10001;
  t = -1;
  while (t < h - 1) {
    m = (h + t) / 2;
    if (Judge())
      h = m;
    else
      t = m;
  }
  cout << h << endl;
  m = h;
  for (int i = 1; i <= n; i++) col[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (!col[i]) {
      s++;
      judge(i, 1);
    }
  }
  for (int i = 1; i <= s; i++) ans = (ans * 2LL) % 1000000007LL;
  cout << ans;
  return 0;
}
