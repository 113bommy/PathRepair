#include <bits/stdc++.h>
using namespace std;
struct rect {
  int x;
  int y;
  char c;
  bool flipped;
} r[4];
int n;
char ch[101][101];
bool done;
void check(int i, int j, int k) {
  int x1, y1, x2, y2, x3, y3, i1, j1;
  if (done) return;
  x1 = r[i].x;
  y1 = r[i].y;
  x2 = r[j].x;
  y2 = r[j].y;
  x3 = r[k].x;
  y3 = r[k].y;
  if (r[i].flipped) swap(x1, y1);
  if (r[j].flipped) swap(x2, y2);
  if (r[k].flipped) swap(x3, y3);
  if (y1 == y2 && y2 == y3) {
    if (x1 + x2 + x3 == y1) {
      n = x1 + x2 + x3;
      done = 1;
      for (i1 = 1; i1 <= x1; i1++) {
        for (j1 = 1; j1 <= y1; j1++) {
          ch[i1][j1] = r[i].c;
        }
      }
      for (i1 = x1 + 1; i1 <= x1 + x2; i1++) {
        for (j1 = 1; j1 <= y2; j1++) {
          ch[i1][j1] = r[j].c;
        }
      }
      for (i1 = x1 + x2 + 1; i1 <= x1 + x2 + x3; i1++) {
        for (j1 = 1; j1 <= y3; j1++) {
          ch[i1][j1] = r[k].c;
        }
      }
    }
  } else if (y1 == y2 + y3) {
    if (x2 == x3 && x1 + x2 == y1) {
      n = y1;
      done = 1;
      for (i1 = 1; i1 <= x1; i1++) {
        for (j1 = 1; j1 <= y1; j1++) {
          ch[i1][j1] = r[i].c;
        }
      }
      for (i1 = x1 + 1; i1 <= x1 + x2; i1++) {
        for (j1 = 1; j1 <= y2; j1++) {
          ch[i1][j1] = r[j].c;
        }
      }
      for (i1 = x1 + 1; i1 <= x1 + x2; i1++) {
        for (j1 = y2 + 1; j1 <= y2 + y3; j1++) {
          ch[i1][j1] = r[k].c;
        }
      }
    }
  }
}
int main() {
  int i, j;
  cin >> r[1].x >> r[1].y >> r[2].x >> r[2].y >> r[3].x >> r[3].y;
  r[1].c = 'A';
  r[2].c = 'B';
  r[3].c = 'C';
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 3; j++) {
      if (i & (1 << j)) {
        r[j + 1].flipped = 1;
      } else {
        r[j + 1].flipped = 0;
      }
    }
    check(1, 2, 3);
    check(1, 3, 2);
    check(2, 1, 3);
    check(2, 3, 1);
    check(3, 1, 2);
    check(3, 2, 1);
  }
  if (done) {
    cout << n << '\n';
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        cout << ch[i][j] << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "-1\n";
  }
  return 0;
}
