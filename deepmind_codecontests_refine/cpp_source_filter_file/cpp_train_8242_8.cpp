#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n, m;
vector<int> row[M], col[M];
int Left, Right, Top, Bottom;
struct STC {
  int x, y, d;
};
STC next(STC o) {
  if (o.d == 1) {
    int max_y = Right;
    for (auto i : row[o.x]) {
      if (i > o.y) max_y = min(max_y, i - 1);
    }
    Right = min(Right, max_y);
    Top++;
    return (STC){o.x, max_y, (o.d + 1) & 3};
  }
  if (o.d == 2) {
    int max_x = Bottom;
    for (auto i : col[o.y]) {
      if (i > o.x) max_x = min(max_x, i - 1);
    }
    Bottom = min(Bottom, max_x);
    Right--;
    return (STC){max_x, o.y, (o.d + 1) & 3};
  }
  if (o.d == 3) {
    int min_y = Left;
    for (auto i : row[o.x]) {
      if (i < o.y) min_y = max(min_y, i + 1);
    }
    Left = max(Left, min_y);
    Bottom--;
    return (STC){o.x, min_y, (o.d + 1) & 3};
  }
  int min_x = Top;
  for (auto i : col[o.y]) {
    if (i < o.x) min_x = max(min_x, i + 1);
  }
  Top = max(Top, min_x);
  Left++;
  return (STC){min_x, o.y, (o.d + 1) & 3};
}
int D(int x) { return x < 0 ? -x : x; }
int k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    row[x].push_back(y);
    col[y].push_back(x);
  }
  Left = 1;
  Right = m;
  Top = 1;
  Bottom = n;
  STC o = (STC){1, 1, 1};
  long long sum = 0;
  while (1) {
    STC t = next(o);
    int dis = D(o.x - t.x) + D(o.y - t.y);
    if (!dis) break;
    sum += dis;
    o = t;
  }
  printf(sum + k + 1 == 1LL * n * m ? "Yes" : "No");
}
