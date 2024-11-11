#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  int x, y;
} s[17];
bool cmp(node a, node b) {
  if (a.y != b.y) return a.y > b.y;
  return a.x > b.x;
}
bool cmp2(node a, node b) {
  if (a.y != b.y) return a.y > b.y;
  return a.x < b.x;
}
int main() {
  for (int i = (1); i <= (4); i++) cin >> s[i].x >> s[i].y;
  for (int i = (5); i <= (8); i++) cin >> s[i].x >> s[i].y;
  sort(s + 1, s + 5, cmp);
  sort(s + 5, s + 9, cmp2);
  swap(s[7], s[8]);
  swap(s[3], s[4]);
  s[9].x = (s[6].x + s[8].x) / 2;
  s[9].y = (s[1].y + s[3].y) / 2;
  for (int i = 5; i <= 9; i++) {
    int flag = 0;
    node pre = s[4];
    for (int j = 0; j < 4; j++) {
      int x2 = pre.x - s[i].x;
      int y2 = pre.y - s[i].y;
      int x1 = s[j + 1].x - pre.x;
      int y1 = s[j + 1].y - pre.y;
      int now = x1 * y2 - x2 * y1;
      if (now > 0) flag = 1;
      pre = s[j + 1];
    }
    if (!flag) {
      cout << "YES";
      return 0;
    }
  }
  for (int i = 1; i <= 4; i++) {
    int flag = 0;
    node pre = s[8];
    for (int j = 4; j < 8; j++) {
      int x2 = pre.x - s[i].x;
      int y2 = pre.y - s[i].y;
      int x1 = s[j + 1].x - pre.x;
      int y1 = s[j + 1].y - pre.y;
      int now = x1 * y2 - x2 * y1;
      if (now > 0) flag = 1;
      pre = s[j + 1];
    }
    if (!flag) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
