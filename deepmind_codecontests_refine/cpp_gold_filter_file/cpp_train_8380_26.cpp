#include <bits/stdc++.h>
const int N = 30;
const int inf = -100000;
using namespace std;
int g[510][510];
int num;
int X, Y, X0, Y0, xx, yy;
int fun(char c) {
  int flag = 0;
  switch (c) {
    case 'R':
      if (yy < Y) yy++;
      break;
    case 'L':
      if (yy > 1) yy--;
      break;
    case 'U':
      if (xx > 1) xx--;
      break;
    case 'D':
      if (xx < X) xx++;
      break;
  }
  if (g[xx][yy] == 0) {
    flag = 1;
    num--;
  }
  g[xx][yy] = 1;
  return flag;
}
int main() {
  char str[100010];
  scanf("%d%d%d%d", &X, &Y, &X0, &Y0);
  scanf("%s", str);
  memset(g, 0, sizeof(g));
  num = X * Y;
  num--;
  xx = X0, yy = Y0;
  g[X0][Y0] = 1;
  cout << "1 ";
  for (int i = 0; i < strlen(str) - 1; i++) {
    cout << fun(str[i]) << " ";
  }
  if (fun(str[strlen(str) - 1])) {
    num++;
    cout << num << endl;
  } else {
    cout << num << endl;
  }
  return 0;
}
