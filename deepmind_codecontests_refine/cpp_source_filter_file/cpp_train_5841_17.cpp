#include <bits/stdc++.h>
using namespace std;
int ax, ay, bx, by, cx, cy, n;
vector<vector<bool>> visited(10000, vector<bool>(10000, false));
bool checkPos(int x, int y) {
  if (x >= n || x < 0 || y >= n || y < 0) {
    return false;
  }
  if (visited[x][y]) {
    return false;
  }
  if (x == ax || y == ay || abs(ay - y) == abs(ax - x)) {
    return false;
  }
  if (x == cx && y == cy) {
    return true;
  }
  visited[x][y] = true;
  return checkPos(x, y + 1) || checkPos(x, y - 1) || checkPos(x + 1, y) ||
         checkPos(x + 1, y + 1) || checkPos(x + 1, y - 1) ||
         checkPos(x - 1, y) || checkPos(x - 1, y + 1) || checkPos(x - 1, y - 1);
}
int main() {
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  if (checkPos(bx, by)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
