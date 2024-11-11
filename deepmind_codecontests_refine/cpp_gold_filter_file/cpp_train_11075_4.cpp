#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx, dy;
int x, y;
char s[100005];
map<int, int> a[100010];
int main() {
  cin >> n >> m;
  cin >> x >> y;
  scanf("%s", s + 1);
  long long sum = 0;
  if (s[1] == 'U')
    dx = -1;
  else
    dx = 1;
  if (s[2] == 'L')
    dy = -1;
  else
    dy = 1;
  int cnt = n + m - 2;
  if (x == 1 || x == n || y == 1 || y == m) {
    a[x][y] = 1;
    cnt--;
  }
  long long ji = 0;
  while (1) {
    ji++;
    if (ji >= 1e7) {
      cout << -1 << endl;
      return 0;
    }
    int dis = int(0x3f3f3f3f);
    if (dx == 1)
      dis = min(dis, n - x);
    else
      dis = min(dis, x - 1);
    if (dy == 1)
      dis = min(dis, m - y);
    else
      dis = min(dis, y - 1);
    x += dx * dis;
    y += dy * dis;
    sum += dis;
    if (x == 1)
      dx = 1;
    else if (x == n)
      dx = -1;
    if (y == 1)
      dy = 1;
    else if (y == m)
      dy = -1;
    if (a[x][y] == 0) {
      cnt--;
      a[x][y] = 1;
    }
    if (!cnt) {
      cout << sum + 1 << endl;
      return 0;
    }
  }
}
