#include <bits/stdc++.h>
using namespace std;
string seq;
struct pos {
  int x, y;
  friend bool operator<(const pos& p1, const pos& p2) {
    return p1.x < p2.x || (p1.x == p1.x && p1.y < p2.y);
  }
};
map<pos, bool> vp;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pos dst;
pos que[1000];
int st[1000];
int getdist() {
  pos cur, next;
  cur.x = cur.y == 0;
  vp[cur] = true;
  int h, t;
  h = 0, t = 1;
  que[0] = cur;
  st[0] = 0;
  for (; h < t; h++) {
    cur = que[h];
    int i;
    for (i = 0; i < 4; i++) {
      next.x = cur.x + dir[i][0];
      next.y = cur.y + dir[i][1];
      if (vp.find(next) != vp.end() && !vp.find(next)->second) {
        vp.find(next)->second = true;
        que[t] = next;
        st[t] = st[h] + 1;
        if (dst.x == next.x && dst.y == cur.y) return st[t];
        t++;
      }
    }
  }
  return -1;
}
int main() {
  cin >> seq;
  int i;
  pos cur;
  cur.x = cur.y = 0;
  vp.insert(make_pair(cur, false));
  for (i = 0; i < seq.size(); i++) {
    switch (seq[i]) {
      case 'L':
        cur.x--;
        break;
      case 'R':
        cur.x++;
        break;
      case 'U':
        cur.y--;
        break;
      case 'D':
        cur.y++;
        break;
    }
    if (vp.find(cur) != vp.end()) break;
    vp.insert(make_pair(cur, false));
  }
  dst = cur;
  if (i == vp.size()) i = getdist();
  if (i < seq.size())
    printf("BUG\n");
  else
    printf("OK\n");
  return 0;
}
