#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct mve {
  int i, t, w;
  mve(int a, int b, int c) : i(a), t(b), w(c) {}
  mve() {}
};
int n, m, cant;
int minx[110], miny[110], mx[110];
int grid[110][110];
string s[2] = {"row", "col"};
vector<mve> moves;
void solve_row() {
  for (int i = 0; i < (int)n; i++)
    if (minx[i]) {
      moves.push_back(mve(i, 0, minx[i]));
      cant += minx[i];
      for (int j = 0; j < (int)m; j++) grid[i][j] -= minx[i];
    }
}
void solve_col() {
  for (int j = 0; j < (int)m; j++)
    if (miny[j]) {
      moves.push_back(mve(j, 0, miny[j]));
      cant += minx[j];
      for (int i = 0; i < (int)n; i++) grid[i][j] -= miny[j];
    }
}
bool solve_row2() {
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) {
      minx[i] = min(minx[i], grid[i][j]);
      mx[i] = max(mx[i], grid[i][j]);
    }
  for (int i = 0; i < (int)n; i++) {
    if (minx[i]) {
      moves.push_back(mve(i, 1, minx[i]));
      cant += minx[i];
    }
    if (minx[i] < mx[i]) {
      printf("-1\n");
      return 0;
    }
  }
  return 1;
}
bool solve_col2() {
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) {
      miny[j] = min(miny[j], grid[i][j]);
      mx[j] = max(mx[j], grid[i][j]);
    }
  for (int j = 0; j < (int)m; j++) {
    if (miny[j]) {
      moves.push_back(mve(j, 1, miny[j]));
      cant += miny[j];
    }
    if (miny[j] < mx[j]) {
      printf("-1\n");
      return 0;
    }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < (int)110; i++) {
    minx[i] = inf;
    miny[i] = inf;
    mx[i] = 0;
  }
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) {
      scanf("%d", &grid[i][j]);
      minx[i] = min(minx[i], grid[i][j]);
      miny[j] = min(miny[j], grid[i][j]);
    }
  cant = 0;
  if (n > m) {
    solve_col();
    if (!solve_row2()) return 0;
  } else {
    solve_row();
    if (!solve_col2()) return 0;
  }
  printf("%d\n", cant);
  for (int i = 0; i < (int)moves.size(); i++) {
    while (moves[i].w--) {
      cout << s[moves[i].t];
      printf(" %d\n", moves[i].i + 1);
    }
  }
  return 0;
}
