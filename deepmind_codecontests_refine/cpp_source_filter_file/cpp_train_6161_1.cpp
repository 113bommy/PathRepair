#include <bits/stdc++.h>
using namespace std;
int n, m;
int db[1005][1005], dw[1005][1005];
pair<int, int> pb[1005][1005], pw[1005][1005];
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
template <class T, class U>
void bfs(int x0, int y0, T d, U p) {
  vector<pair<int, int>> q = {{x0, y0}};
  size_t qs = 0;
  memset(d, 63, sizeof(db));
  d[x0][y0] = 0;
  p[x0][y0] = {-1, -1};
  while (qs != q.size()) {
    auto [x, y] = q[qs++];
    for (int dir = 0; dir < 8; dir++) {
      int xx = x + dx[dir];
      int yy = y + dy[dir];
      if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
      if (d[xx][yy] > 1231231) {
        d[xx][yy] = d[x][y] + 1;
        p[xx][yy] = {x, y};
        q.emplace_back(xx, yy);
      }
    }
  }
}
pair<int, int> gmv() {
  int x, y;
  cin >> x >> y;
  if (x == -1 || y == -1) exit(1);
  return {x, y};
}
void pmv(int x, int y) { cout << x << ' ' << y << '\n' << flush; }
bool jed(int x, int y, int ax, int ay) {
  x = abs(x - ax);
  y = abs(y - ay);
  return x * y == 2 && x + y == 3;
}
void player(string s) { cout << s << '\n' << flush; }
template <class T>
void dbg(T dw) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cerr << dw[i][j] << " \n"[j == m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n >> m;
  int xw, yw, xb, yb;
  cin >> xw >> yw >> xb >> yb;
  int txw = n / 2, tyw = m / 2;
  int txb = n / 2 + 1, tyb = m / 2;
  bfs(txw, tyw, dw, pw);
  bfs(txb, tyb, db, pb);
  if ((xw + yw + xb + yb) % 2 == 0) {
    if (dw[xw][yw] >= dw[xb][yb]) {
      player("BLACK");
      while (dw[xb][yb] > 0) {
        tie(xw, yw) = gmv();
        tie(xb, yb) = pw[xb][yb];
        pmv(xb, yb);
        if (xb == xw && yb == yw) return 0;
        ;
      }
      {
        tie(xw, yw) = gmv();
        if (jed(xw, yw, xb, yb)) {
          pmv(xw, yw);
          return 0;
        } else {
          xb -= 1, yb += 2;
          pmv(xb, yb);
        }
      }
      {
        tie(xw, yw) = gmv();
        if (jed(xw, yw, xb, yb)) {
          pmv(xw, yw);
          return 0;
        } else {
          xb += 2, yb -= 1;
          pmv(xb, yb);
        }
      }
      {
        tie(xw, yw) = gmv();
        if (jed(xw, yw, xb, yb)) {
          pmv(xw, yw);
          return 0;
        } else {
          xb -= 2, yb -= 1;
          pmv(xb, yb);
          return 0;
        }
      }
    }
    if (db[xb][yb] < dw[xw][yw]) {
      player("BLACK");
      while (db[xb][yb] > 0) {
        tie(xw, yw) = gmv();
        tie(xb, yb) = pb[xb][yb];
        pmv(xb, yb);
        if (xb == xw && yb == yw) return 0;
        ;
      }
      return 0;
    }
    {
      player("WHITE");
      while (dw[xw][yw] > 0) {
        tie(xw, yw) = pw[xw][yw];
        pmv(xw, yw);
        tie(xb, yb) = gmv();
      }
      return 0;
    }
  } else {
    if (db[xw][yw] <= db[xb][yb]) {
      player("WHITE");
      while (db[xw][yw] > 0) {
        tie(xw, yw) = pb[xw][yw];
        pmv(xw, yw);
        if (xb == xw && yb == yw) return 0;
        ;
        tie(xb, yb) = gmv();
      }
      {
        if (jed(xw, yw, xb, yb)) {
          pmv(xb, yb);
          return 0;
        }
        xw += 2, yw += 1;
        pmv(xw, yw);
        tie(xb, yb) = gmv();
      }
      {
        if (jed(xw, yw, xb, yb)) {
          pmv(xb, yb);
          return 0;
        }
        xw -= 2, yw += 1;
        pmv(xw, yw);
        tie(xb, yb) = gmv();
      }
      {
        if (jed(xw, yw, xb, yb)) {
          pmv(xb, yb);
          return 0;
        }
        xw += 1, yw -= 2;
        pmv(xw, yw);
        return 0;
      }
    }
    if (dw[xw][yw] <= db[xb][yb]) {
      player("WHITE");
      while (dw[xw][yw] > 0) {
        tie(xw, yw) = pw[xw][yw];
        pmv(xw, yw);
        if (xb == xw && yb == yw) return 0;
        ;
        tie(xb, yb) = gmv();
      }
      return 0;
    }
    {
      player("BLACK");
      while (db[xb][yb] > 0) {
        tie(xw, yw) = gmv();
        tie(xb, yb) = pb[xb][yb];
        pmv(xb, yb);
      }
      return 0;
    }
  }
}
