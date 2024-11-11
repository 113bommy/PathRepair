#include <bits/stdc++.h>
using namespace std;
struct op {
  int xa, ya, xb, yb;
  void print(int x) {
    if (!x) {
      printf("%d %d %d %d\n", xa, ya, xb, yb);
    } else {
      printf("%d %d %d %d\n", xb, yb, xa, ya);
    }
  }
};
int n, m;
struct node {
  int a[55][55];
  vector<op> v;
  void add(int xa, int ya, int xb, int yb) {
    v.push_back((op){xa, ya, xb, yb});
    a[xb][yb] = a[xa][ya];
    a[xa][ya] = 0;
  }
  void move(int x, int y) {
    if (a[x][y + 1]) {
      move(x, y + 1);
    }
    add(x, y, x, y + 1);
  }
  void work1() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (!a[i][j]) {
          continue;
        }
        cnt++;
        int x = j;
        while (x > cnt) {
          add(i, x, i, x - 1);
          x--;
        }
        while (x < cnt) {
          move(i, x);
          x++;
        }
        for (int k = i - 1; k; k--) {
          add(k + 1, x, k, x);
        }
      }
    }
  }
  void work2(int *s, int *f) {
    if (n == 2) {
      if (s[1] != f[1]) {
        add(1, 1, 2, 1);
        add(2, 1, 2, 2);
        add(1, 2, 1, 1);
        add(2, 2, 1, 2);
      }
      return;
    }
    for (int i = 1; i <= m; i++) {
      int j;
      for (j = 1; j <= m; j++) {
        if (s[i] == f[j]) {
          break;
        }
      }
      add(1, i, 2, i);
      int x = i;
      while (x < j) {
        add(2, x, 2, x + 1);
        x++;
      }
      while (x > j) {
        add(2, x, 2, x - 1);
        x--;
      }
      add(2, x, 3, x);
    }
    for (int i = 1; i <= m; i++) {
      add(3, i, 2, i);
      add(2, i, 1, i);
    }
  }
} a, b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a.a[x][y] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    b.a[x][y] = i;
  }
  a.work1();
  b.work1();
  a.work2(a.a[1], b.a[1]);
  printf("%d\n", a.v.size() + b.v.size());
  for (int i = 0; i < a.v.size(); i++) {
    a.v[i].print(0);
  }
  for (int i = b.v.size() - 1; i >= 0; i--) {
    b.v[i].print(1);
  }
  return 0;
}
