#include <bits/stdc++.h>
using namespace std;
char s[1505];
int mm[1505][1505];
int flag[1505][1505][3];
queue<pair<int, int> > mq;
int vx[] = {-1, 0, 1, 0};
int vy[] = {0, -1, 0, 1};
int fun(int x, int n) {
  int r = x % n;
  if (x < 0) {
    r += n;
  }
  return r;
}
int main() {
  int n, m;
  int b_x, b_y;
  cin >> n >> m;
  for (int i = (0); i < (int)(n); i++) {
    scanf("%s", s);
    for (int j = (0); j < (int)(m); j++) {
      if (s[j] == '#') {
        mm[i][j] = 0;
      } else if (s[j] == '.') {
        mm[i][j] = 1;
      } else if (s[j] == 'S') {
        mm[i][j] = 1;
        b_x = i;
        b_y = j;
      }
    }
  }
  mq.push(make_pair(b_x, b_y));
  flag[b_x][b_y][0] = 1;
  flag[b_x][b_y][1] = b_x;
  flag[b_x][b_y][2] = b_y;
  int res_flag = 0;
  while (!mq.empty() && !res_flag) {
    int n_x = mq.front().first;
    int n_y = mq.front().second;
    mq.pop();
    for (int i = (0); i < (int)(4); i++) {
      int t_x = n_x + vx[i];
      int t_y = n_y + vy[i];
      int t_i = fun(t_x, n);
      int t_j = fun(t_y, m);
      if (mm[t_i][t_j] == 1) {
        if (flag[t_i][t_j][0] == 0) {
          flag[t_i][t_j][0] = 1;
          flag[t_i][t_j][1] = t_x;
          flag[t_i][t_j][2] = t_y;
          mq.push(make_pair(t_x, t_y));
        } else {
          if (!(flag[t_i][t_j][1] == t_x && flag[t_i][t_j][2] == t_y)) {
            res_flag = 1;
            break;
          }
        }
      }
    }
  }
  if (res_flag) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
