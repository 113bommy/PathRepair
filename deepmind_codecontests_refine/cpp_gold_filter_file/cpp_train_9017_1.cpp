#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> mp;
int x, y;
char c;
int xx[5] = {0, -1, 0, 1};
int yy[5] = {-1, 0, 1, 0};
int main() {
  mp[make_pair(x, y)] = 1;
  while (scanf("%c", &c) && c != '\n') {
    int p1 = x;
    int p2 = y;
    switch (c) {
      case 'L':
        --x;
        break;
      case 'R':
        ++x;
        break;
      case 'U':
        ++y;
        break;
      case 'D':
        --y;
        break;
    }
    if (mp[make_pair(x, y)]) {
      cout << "BUG";
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      int vi = x + xx[i];
      int vj = y + yy[i];
      if (mp[make_pair(vi, vj)] && !(p1 == vi && p2 == vj)) {
        cout << "BUG";
        return 0;
      }
    }
    mp[make_pair(x, y)] = 1;
  }
  cout << "OK";
  return 0;
}
