#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
struct data {
  int x, y;
  void get() {
    x = read();
    y = read();
  }
} a[4], b[4];
bool isin1(int x, int y) {
  int LEFT = 1000, RIGHT = -1000, UP = -1000, DOWN = 1000;
  for (int i = 0; i < 4; i++)
    LEFT = min(LEFT, a[i].x), RIGHT = max(RIGHT, a[i].x), UP = max(UP, a[i].y),
    DOWN = min(DOWN, a[i].y);
  if (LEFT <= x && RIGHT >= x && UP >= y && DOWN <= y)
    return 1;
  else
    return 0;
}
bool isin2(int x, int y) {
  int LEFT = 1000, RIGHT = -1000, UP = -1000, DOWN = 1000;
  for (int i = 0; i < 4; i++)
    LEFT = min(LEFT, b[i].x), RIGHT = max(RIGHT, b[i].x), UP = max(UP, b[i].y),
    DOWN = min(DOWN, b[i].y);
  int mid1 = (LEFT + RIGHT) / 2, mid2 = (UP + DOWN) / 2;
  if (abs(x - mid1) + abs(y - mid2) <= mid1 - LEFT)
    return 1;
  else
    return 0;
}
void win() {
  cout << "Yes";
  exit(0);
}
signed main() {
  for (int i = 0; i < 4; i++) a[i].get();
  for (int i = 0; i < 4; i++) b[i].get();
  for (int i = -100; i <= 100; i++)
    for (int j = -100; j <= 100; j++)
      if (isin1(i, j) && isin2(i, j)) win();
  cout << "No";
  return 0;
}
