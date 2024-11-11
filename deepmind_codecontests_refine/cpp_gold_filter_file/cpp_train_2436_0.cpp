#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int y;
  node(int a, int b) : x(a), y(b) {}
  node() : x(0), y(0) {}
};
bool operator<(const node &a, const node &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int main() {
  map<char, int> dir;
  dir['U'] = 0;
  dir['D'] = 1;
  dir['L'] = 2;
  dir['R'] = 3;
  int dirdir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  node des;
  cin >> des.x >> des.y;
  string s;
  cin >> s;
  set<node> scope;
  scope.insert(node(0, 0));
  node move(0, 0);
  for (int i = 0; i < s.size(); i++) {
    move.x += dirdir[dir[s[i]]][0];
    move.y += dirdir[dir[s[i]]][1];
    scope.insert(move);
  }
  node source(0, 0);
  bool flag = false;
  for (set<node>::iterator it = scope.begin(); it != scope.end(); it++) {
    if (move.x == 0 && move.y == 0)
      flag |= ((*it).x == des.x && (*it).y == des.y);
    else if (move.x == 0 && move.y != 0)
      flag |= ((*it).x == des.x && (des.y - (*it).y) % move.y == 0 &&
               des.y * 1ll * move.y >= 0);
    else if (move.x != 0 && move.y == 0)
      flag |= ((*it).y == des.y && (des.x - (*it).x) % move.x == 0 &&
               des.x * 1ll * move.x >= 0);
    else if (((des.x - (*it).x) * 1ll * move.y ==
              (des.y - (*it).y) * 1ll * move.x) &&
             (des.x - (*it).x) % move.x == 0 &&
             (des.y - (*it).y) % move.y == 0 &&
             (des.x - (*it).x) * 1ll * move.x >= 0)
      flag = true;
    if (flag) break;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
