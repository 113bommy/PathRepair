#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void maz(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void miz(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
const int N = 40, lgN = 20;
const int INF = 2000000000;
int n, m, *A[N], *B[N];
bool fail;
bool rev;
vector<std::pair<int, int> > ans;
int *bA[N];
void print(int **A, int n, int m) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      printf("%d%c", A[i][j], j == m - 1 ? '\n' : ' ');
}
int **reflex(int n, int m, int **A) {
  int **B = new int *[m];
  for (int i = 0; i < m; i++) B[i] = new int[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) B[j][i] = A[i][j];
  return B;
}
bool same(int **A, int **B, int n, int m) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (A[i][j] != B[i][j]) return false;
  return true;
}
void find_c(int n, int m, int p, int **A, int c, int &x, int &y) {
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
      if (i + j == 0)
        continue;
      else if (j == m - 1 && i >= p)
        return;
      else if (A[i][j] == c) {
        x = i;
        y = j;
        return;
      }
}
enum { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, RU = 4, RD = 5, LD = 6, LU = 7 };
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1}, dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
void udlr(int **A, int &x, int &y, int d) {
  swap(A[x][y], A[x + dx[d]][y + dy[d]]);
  x += dx[d];
  y += dy[d];
  if (rev)
    ans.push_back(std::make_pair(y, x));
  else
    ans.push_back(std::make_pair(x, y));
}
void d_move(int **A, int &x, int &y, int a, int b) {
  while (x != a || y != b) {
    if (x > a)
      udlr(A, x, y, 0);
    else if (x < a)
      udlr(A, x, y, 1);
    else if (y > b)
      udlr(A, x, y, 2);
    else if (y < b)
      udlr(A, x, y, 3);
  }
}
void make_up(int **A, int &x, int &y) {
  udlr(A, x, y, DOWN);
  if (x == 1) return;
  if (y > 0) {
    udlr(A, x, y, LU);
    udlr(A, x, y, RU);
    make_up(A, x, y);
  } else {
    udlr(A, x, y, RU);
    udlr(A, x, y, LU);
    make_up(A, x, y);
  }
}
void make_right(int **A, int &x, int &y, int m) {
  udlr(A, x, y, RU);
  udlr(A, x, y, LEFT);
  if (y == m - 2) return;
  udlr(A, x, y, RD);
  make_right(A, x, y, m);
}
void make_down(int **A, int &x, int &y, int n) {
  udlr(A, x, y, RD);
  udlr(A, x, y, UP);
  if (x == n - 2) return;
  udlr(A, x, y, LD);
  make_down(A, x, y, n);
}
void just_go(int x, int a, int **A) {
  if (x == a) return;
  if (x < a) {
    for (int i = x + 1; i <= a; i++) swap(A[0][i], A[0][i - 1]);
  } else {
    for (int i = x - 1; i >= a; i--) swap(A[0][i], A[0][i + 1]);
  }
}
void solve1(int n, int m, int **A, int **B) {
  if (n > m) {
    int **C, **D;
    C = reflex(n, m, A);
    D = reflex(n, m, B);
    rev ^= 1;
    return solve1(m, n, C, D);
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      just_go(i, j, A);
      if (same(A, B, 1, m)) {
        int x = 0, y = i;
        if (rev)
          ans.push_back(std::make_pair(y, x));
        else
          ans.push_back(std::make_pair(x, y));
        d_move(A, x, y, 0, j);
        return;
      }
      just_go(j, i, A);
    }
  fail = true;
}
void solve22(int **A, int **B) {
  int x = 0, y = 0;
  int step = 0;
  while (true) {
    if (same(A, B, 2, 2)) return;
    if (step > 1000) {
      fail = true;
      return;
    }
    while (true) {
      int r = rand() % 8;
      int a = x + dx[r], b = y + dy[r];
      if (a < 0 || a >= 2 || b < 0 || b >= 2) continue;
      udlr(A, x, y, r);
      step++;
      break;
    }
  }
}
void solve(int n, int m, int **A, int **B) {
  if (n > m) {
    int **C, **D;
    C = reflex(n, m, A);
    D = reflex(n, m, B);
    rev ^= 1;
    return solve(m, n, C, D);
  }
  if (n == 2 && m == 2) return solve22(A, B);
  for (int i = n - 1; i >= 0; i--) {
    int x = -1, y = -1;
    if (A[i][m - 1] == B[i][m - 1]) continue;
    find_c(n, m, i, A, B[i][m - 1], x, y);
    if (x == -1) {
      fail = true;
      return;
    }
    int nowx = 0, nowy = 0;
    if (x == 0) {
      d_move(A, nowx, nowy, x, y - 1);
      udlr(A, nowx, nowy, RD);
    } else {
      d_move(A, nowx, nowy, x - 1, y);
      make_up(A, nowx, nowy);
    }
    if (nowy == m - 1)
      udlr(A, nowx, nowy, LU);
    else
      make_right(A, nowx, nowy, m);
    if (nowx == i)
      d_move(A, nowx, nowy, 0, 0);
    else {
      make_down(A, nowx, nowy, i + 1);
      d_move(A, nowx, nowy, 0, 0);
    }
  }
  solve(n, m - 1, A, B);
}
int main() {
  for (int i = 0; i < N; i++) A[i] = new int[N], bA[i] = new int[N];
  for (int i = 0; i < N; i++) B[i] = new int[N];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &A[i][j]), bA[i][j] = A[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &B[i][j]);
  if (min(n, m) == 1)
    solve1(n, m, A, B);
  else {
    if (A[0][0] != B[0][0]) {
      int x = -1, y;
      find_c(n, m, N, A, B[0][0], x, y);
      if (x == -1) {
        puts("-1");
        return 0;
      }
      ans.push_back(std::make_pair(x, y));
      d_move(A, x, y, 0, 0);
    } else
      ans.push_back(std::make_pair(0, 0));
    solve(n, m, A, B);
  }
  if (fail)
    puts("-1");
  else {
    printf("%d\n", ans.size() - 1);
    for (int i = 0; i < ans.size(); i++)
      printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
}
