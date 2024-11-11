#include <bits/stdc++.h>
using namespace std;
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cerr << *i << ' ';
  cerr << endl;
}
vector<string> table;
int R, C;
int in(int r, int c) { return 0 <= r && r < R && 0 <= c && c < C; }
const int dr[] = {0, -1, 0, +1, 0, -1, 0, +1};
const int dc[] = {+1, 0, -1, 0, +1, 0, -1, 0};
struct IP {
  int r, c;
  int dp, cp;
  IP& ref();
  IP move() {
    if (ref().r != -1) return ref();
    int nr = r, nc = c;
    while (in(nr, nc) && table[nr][nc] == table[r][c]) {
      nr += dr[dp];
      nc += dc[dp];
    }
    nr -= dr[dp];
    nc -= dc[dp];
    while (in(nr, nc) && table[nr][nc] == table[r][c]) {
      nr += dr[dp + cp];
      nc += dc[dp + cp];
    }
    nr -= dr[dp + cp];
    nc -= dc[dp + cp];
    nr += dr[dp];
    nc += dc[dp];
    int ndp = dp, ncp = cp;
    if (!in(nr, nc) || table[nr][nc] == '0') {
      nr = r;
      nc = c;
      if (cp == 1) {
        ncp = 3;
      } else {
        ncp = 1;
        ndp = (dp + 3) & 3;
      }
    } else {
      ndp = dp;
      ncp = cp;
    }
    IP next = *this;
    next.r = nr;
    next.c = nc;
    next.dp = ndp;
    next.cp = ncp;
    return ref() = next;
  }
  void print() {
    cout << table[r][c] << " (" << r << "," << c << ") " << dp << " " << cp
         << endl;
  }
} ip[50][50][4][2];
IP& IP::ref() { return ip[r][c][dp][cp]; }
int main() {
  int STEP;
  cin >> R >> STEP;
  for (int i = 0; i < (int)(R); ++i) {
    string s;
    cin >> s;
    table.push_back(s);
  }
  C = table[0].size();
  for (int i = 0; i < (int)(50); ++i)
    for (int j = 0; j < (int)(50); ++j)
      for (int d = 0; d < (int)(4); ++d)
        for (int c = 0; c < (int)(2); ++c) ip[i][j][d][c].r = -1;
  IP cur;
  cur.r = 0, cur.c = 0, cur.dp = 0, cur.cp = 1;
  for (int s = 0; s < (int)(STEP); ++s) {
    cur = cur.move();
  }
  cout << table[cur.r][cur.c] << endl;
  return 0;
}
