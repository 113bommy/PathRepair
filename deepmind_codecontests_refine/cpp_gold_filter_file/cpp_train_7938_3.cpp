#include <bits/stdc++.h>
using namespace std;
long long int n, k, l, m, t, a, b, r, c, temp1, temp2, x, y, temp, q, d,
    mod = 1e9 + 7, w, p;
bool vis[102][102];
long long int cnt = 0;
void traverseRow(long long int &x, long long int &y) {
  if (y == 1) {
    while (y <= m) {
      if (!vis[x][y]) {
        cout << x << " " << y << endl;
        vis[x][y] = true;
        cnt++;
      }
      y++;
    }
    y = m;
  } else {
    while (y >= 1) {
      if (!vis[x][y]) {
        cout << x << " " << y << endl;
        vis[x][y] = true;
        cnt++;
      }
      y--;
    }
    y = 1;
  }
}
void move() {
  if (!vis[1][1]) {
    while (vis[x][y]) x--;
  } else
    while (vis[x][y] && x < n) x++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> x >> y;
  while (y >= 1) {
    vis[x][y] = true;
    cout << x << " " << y << endl;
    cnt++;
    y--;
  }
  y = 1;
  while (cnt < (n * m)) {
    traverseRow(x, y);
    move();
  }
}
