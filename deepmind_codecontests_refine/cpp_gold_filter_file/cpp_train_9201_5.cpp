#include <bits/stdc++.h>
using namespace std;
int _G[299][299];
bool _inQueue[299][299];
queue<pair<int, int> > q;
int main(void) {
  int n = 0;
  int t = 0;
  scanf("%d %d", &n, &t);
  _G[(0) + (144)][(0) + (144)] = n;
  _inQueue[(0) + (144)][(0) + (144)] = true;
  q.push(pair<int, int>(0, 0));
  while (!q.empty()) {
    pair<int, int> tx = q.front();
    q.pop();
    int x = tx.first;
    int y = tx.second;
    _inQueue[(x) + (144)][(y) + (144)] = false;
    int addIt = _G[(x) + (144)][(y) + (144)] / 4;
    _G[(x) + (144)][(y) + (144)] %= 4;
    _G[(x - 1) + (144)][(y) + (144)] += addIt;
    _G[(x) + (144)][(y - 1) + (144)] += addIt;
    _G[(x + 1) + (144)][(y) + (144)] += addIt;
    _G[(x) + (144)][(y + 1) + (144)] += addIt;
    if (_G[(x - 1) + (144)][(y) + (144)] >= 4 &&
        !_inQueue[(x - 1) + (144)][(y) + (144)]) {
      _inQueue[(x - 1) + (144)][(y) + (144)] = true;
      q.push(pair<int, int>(x - 1, y));
    }
    if (_G[(x) + (144)][(y - 1) + (144)] >= 4 &&
        !_inQueue[(x) + (144)][(y - 1) + (144)]) {
      _inQueue[(x) + (144)][(y - 1) + (144)] = true;
      q.push(pair<int, int>(x, y - 1));
    }
    if (_G[(x + 1) + (144)][(y) + (144)] >= 4 &&
        !_inQueue[(x + 1) + (144)][(y) + (144)]) {
      _inQueue[(x + 1) + (144)][(y) + (144)] = true;
      q.push(pair<int, int>(x + 1, y));
    }
    if (_G[(x) + (144)][(y + 1) + (144)] >= 4 &&
        !_inQueue[(x) + (144)][(y + 1) + (144)]) {
      _inQueue[(x) + (144)][(y + 1) + (144)] = true;
      q.push(pair<int, int>(x, y + 1));
    }
  }
  while (t--) {
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    if (x < -144 || x > 144 || y < -144 || y > 144)
      puts("0");
    else
      printf("%d\n", _G[(x) + (144)][(y) + (144)]);
  }
  while (getchar() != EOF)
    ;
  return 0;
}
