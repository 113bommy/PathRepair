#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long inL() {
  long long x;
  scanf("%lld", &x);
  return x;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
long long toNumber(string s) {
  stringstream ss;
  long long n;
  ss << s;
  ss >> n;
  return n;
}
struct board {
  char type;
  int x, y;
};
board data[9];
int kx, ky;
int dist(int a, int b, int x, int y) { return max(abs(a - b), abs(x - y)); }
void upd(board &was, board &cur) {
  if (was.type == '?' ||
      dist(kx, ky, was.x, was.y) > dist(kx, ky, cur.x, cur.y)) {
    was = cur;
  }
}
int main() {
  for (int i = 0; i < 9; i++) data[i].type = '?';
  int n = in();
  vector<pair<long long, long long> > R, B, Q;
  kx = in(), ky = in();
  for (int i = 0; i < n; i++) {
    board cur;
    cin >> cur.type >> cur.x >> cur.y;
    int dir = -1;
    if (kx == cur.x && ky > cur.y)
      dir = 0;
    else if (kx == cur.x && ky < cur.y)
      dir = 1;
    else if (ky == cur.y && kx > cur.x)
      dir = 2;
    else if (ky == cur.y && kx < cur.x)
      dir = 3;
    else if ((cur.x - kx) == (cur.y - ky) && cur.x < kx)
      dir = 4;
    else if ((cur.x - kx) == (cur.y - ky) && cur.x > kx)
      dir = 5;
    else if ((kx - cur.x) == (cur.y - ky) && cur.y < ky)
      dir = 6;
    else if ((kx - cur.x) == (cur.y - ky) && cur.y > ky)
      dir = 7;
    if (dir >= 0) upd(data[dir], cur);
  }
  for (int i = 0; i < 4; i++)
    if (data[i].type == 'R' || data[i].type == 'Q') {
      cout << "YES" << '\n';
      return 0;
    }
  for (int i = 4; i < 8; i++)
    if (data[i].type == 'B' || data[i].type == 'Q') {
      cout << "YES" << '\n';
      return 0;
    }
  cout << "NO" << '\n';
  return 0;
}
