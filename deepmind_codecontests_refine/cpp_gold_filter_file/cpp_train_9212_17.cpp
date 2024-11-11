#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 100;
int a1, b1, a2, b2, a3, b3;
char mp[200][200];
int n;
bool draw(int x, int y, int xx, int yy, char c) {
  if (xx > n || yy > n) return false;
  for (int i = x; i <= xx; i++) {
    for (int j = y; j <= yy; j++) {
      if (mp[i][j] != 0) return false;
      mp[i][j] = c;
    }
  }
  return true;
}
void cancel(char c) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == c) mp[i][j] = 0;
    }
  }
}
bool calu(int a, int b) {
  int x = 0, y = 0, cnt;
  for (int i = 1; i <= n; i++) {
    cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == 0) cnt++;
    }
    if (cnt) x++, y = max(y, cnt);
  }
  if ((x == a && y == b) || (x == b && y == a))
    return true;
  else
    return false;
}
void fill() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == 0) mp[i][j] = 'C';
    }
  }
}
void print() {
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%c", mp[i][j]);
    }
    printf("\n");
  }
}
int main() {
  scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
  int sum = a1 * b1 + a2 * b2 + a3 * b3;
  int tmp = sqrt(1.0 * sum);
  n = tmp;
  if (tmp * tmp != sum)
    printf("-1\n");
  else {
    bool ans = false;
    int qingkuang = 0;
    int w, h;
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= a1; i++)
      for (int j = 1; j <= b1; j++) mp[i][j] = 'A';
    if (a1 == tmp || b1 == tmp)
      qingkuang = 0;
    else
      qingkuang = 1;
    if (qingkuang == 0) {
      int x, y, w, h;
      if (a1 == tmp)
        w = tmp - b1, h = tmp, x = 1, y = b1 + 1;
      else
        w = tmp, h = tmp - a1, x = a1 + 1, y = 1;
      if (draw(x, y, x + a2 - 1, y + b2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
      if (draw(x, y, x + b2 - 1, y + a2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
    } else {
      int x, y, w, h;
      int xx, yy;
      x = 1, y = b1 + 1;
      xx = a1 + 1, yy = 1;
      if (draw(x, y, x + a2 - 1, y + b2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
      if (draw(x, y, x + b2 - 1, y + a2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
      if (draw(xx, yy, xx + b2 - 1, yy + a2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
      if (draw(xx, yy, xx + a2 - 1, yy + b2 - 1, 'B') && calu(a3, b3)) {
        ans = true;
        fill();
        print();
        return 0;
      } else
        cancel('B');
    }
    printf("-1\n");
  }
  return 0;
}
