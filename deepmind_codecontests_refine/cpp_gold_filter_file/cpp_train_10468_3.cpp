#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1.0);
const long long M = 1e7 + 9;
const int si = 1e5 + 9;
char c, r;
int x, y;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int inside(int x, int y) {
  int c = 0;
  if (x >= 0 && x <= 7 && y >= 0 && y <= 7) c++;
  return c;
}
int main() {
  cin >> r >> c;
  x = r - 'a';
  y = c - '1';
  int ans = 0;
  for (int k = 0; k < 8; k++) {
    ans += inside(x + dx[k], y + dy[k]);
  }
  cout << ans;
  return 0;
  ;
}
