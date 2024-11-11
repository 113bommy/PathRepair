#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const int INF = 0x3f3f3f3f;
struct chess {
  int x, y, dir;
  char role;
};
chess s[10];
int sx, sy;
bool gecmp(chess x, int num) {
  if (s[num].role == 'K') return false;
  chess y;
  y.x = s[num].x;
  y.y = s[num].y;
  y.role = s[num].role;
  int disx = max(abs(x.x - sx), abs(x.y - sy));
  int disy = max(abs(y.x - sx), abs(y.y - sy));
  return disx >= disy;
}
int assign_dir(int x, int y) {
  if (x == sx && y > sy) return 0;
  if (x == sx && y < sy) return 1;
  if (y == sy && x < sx) return 2;
  if (y == sy && x > sx) return 3;
  if ((x - sx) == (sy - y) && x < sx) return 4;
  if ((x - sx) == (sy - y) && x > sx) return 5;
  if ((x - sx) == (y - sy) && x < sx) return 6;
  if ((x - sx) == (y - sy) && x > sx) return 7;
  return -1;
}
inline char in_char() {
  char c = '\0';
  while (c <= ' ') c = getchar();
  return c;
}
inline int in_int() {
  int n;
  scanf("%d", &n);
  return n;
}
int main() {
  int n;
  n = in_int();
  {
    sx = in_int();
    sy = in_int();
    for (int i = 0; i < 8; i++) s[i].role = 'K';
    for (int i = 0; i < n; i++) {
      chess tmp;
      tmp.role = in_char();
      tmp.x = in_int();
      tmp.y = in_int();
      int dir = assign_dir(tmp.x, tmp.y);
      if (dir == -1) continue;
      tmp.dir = dir;
      if (!gecmp(tmp, dir)) {
        s[dir].x = tmp.x;
        s[dir].y = tmp.y;
        s[dir].role = tmp.role;
        s[dir].dir = dir;
      }
    }
    bool flag = false;
    for (int i = 0; i <= 3; i++)
      if (s[i].role == 'R' || s[i].role == 'Q') flag = true;
    for (int i = 4; i < 8; i++)
      if (s[i].role == 'B' || s[i].role == 'Q') flag = true;
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
