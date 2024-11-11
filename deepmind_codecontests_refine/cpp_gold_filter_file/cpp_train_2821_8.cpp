#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
inline int gi() {
  char ch = getchar();
  int q = 0, x = 0;
  while (ch < '0' || ch > '9') q = (ch == '-' ? 1 : q), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return q ? (-x) : x;
}
struct data {
  int x, y, id;
  bool operator<(const data &c) const {
    if (x != c.x) return x < c.x;
    return y < c.y;
  }
} p[N];
struct Ans {
  int x, y, X, Y;
} w[N];
int m, n, top;
void move(int x1, int y1, int x2, int y2) {
  while (x1 != x2)
    if (x1 < x2)
      w[++top] = (Ans){x1, y1, x1 + 1, y1}, ++x1;
    else
      w[++top] = (Ans){x1, y1, x1 - 1, y1}, --x1;
  while (y1 != y2)
    if (y1 < y2)
      w[++top] = (Ans){x1, y1, x1, y1 + 1}, ++y1;
    else
      w[++top] = (Ans){x1, y1, x1, y1 - 1}, --y1;
  return;
}
void solve() {
  for (int i = 1; i <= m; ++i)
    if (i < p[i].x) move(p[i].x, p[i].y, i, p[i].y), p[i].x = i;
  for (int i = m; i >= 1; --i) move(p[i].x, p[i].y, i, p[i].y), p[i].x = i;
  for (int i = 1; i <= m; ++i)
    move(p[i].x, p[i].y, p[i].x, p[i].id), p[i].y = p[i].id;
  for (int i = 1; i <= m; ++i) move(p[i].x, p[i].y, p[i].id, p[i].y);
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) p[i] = (data){gi(), gi(), i};
  sort(p + 1, p + m + 1), solve();
  int tmp = top;
  for (int i = 1; i <= m; ++i) p[i] = (data){gi(), gi(), i};
  sort(p + 1, p + m + 1), solve();
  cout << top << endl;
  for (int i = 1; i <= tmp; ++i)
    cout << w[i].x << " " << w[i].y << " " << w[i].X << " " << w[i].Y << endl;
  for (int i = top; i > tmp; --i)
    cout << w[i].X << " " << w[i].Y << " " << w[i].x << " " << w[i].y << endl;
  return 0;
}
