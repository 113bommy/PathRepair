#include <bits/stdc++.h>
using namespace std;
int dsu[2 * 3000 * 3000 + 10];
int rnk[2 * 3000 * 3000 + 10];
vector<int> mod, pos;
int Find(int x) {
  if (dsu[x] == x) return x;
  return Find(dsu[x]);
}
void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (rnk[x] < rnk[y]) {
    mod.push_back(dsu[x]);
    pos.push_back(x);
    dsu[x] = y;
  } else {
    mod.push_back(dsu[y]);
    pos.push_back(y);
    dsu[y] = x;
  }
  if (rnk[x] == rnk[y]) rnk[x]++, rnk[y]++;
}
void Rollback(int s) {
  while ((int)mod.size() > s) {
    dsu[pos.back()] = mod.back();
    pos.pop_back();
    mod.pop_back();
  }
}
int usd[3100][2 * 3100];
int dx[] = {1, 0, -1, 1, 0, -1, 1, -1};
int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
int main() {
  ios::sync_with_stdio(0);
  int r, c, n;
  cin >> r >> c >> n;
  if (c == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < 2 * 3000 * 3000 + 10; ++i) dsu[i] = i, rnk[i] = 1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    usd[x][y] = 1;
    usd[x][y + c] = 1;
    int st = mod.size();
    vector<int> cx, cy;
    for (int k = 0; k < 8; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      ny = (ny + 2 * c) % (2 * c);
      if (0 <= nx && nx < r) {
        if (usd[nx][ny]) cx.push_back(nx), cy.push_back(ny);
        if (usd[nx][ny]) Union(2 * x * c + y, 2 * nx * c + ny);
      }
    }
    y += c;
    for (int k = 0; k < 8; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      ny = (ny + c + c) % (2 * c);
      if (0 <= nx && nx < r) {
        if (usd[nx][ny]) Union(2 * x * c + y, 2 * nx * c + ny);
      }
    }
    int fl = 1;
    for (int j = 0; j < (int)cx.size(); ++j) {
      if (Find(2 * cx[j] * c + cy[j]) == Find(2 * cx[j] * c + c + cy[j]))
        fl = 0;
    }
    ans += fl;
    y -= c;
    if (!fl) Rollback(st), usd[x][y] = 0, usd[x][y + c] = 0;
  }
  cout << ans << endl;
  return 0;
}
