#include <bits/stdc++.h>
using namespace std;
long long danhdau[10002000];
long long check = 0;
long long n, ax, ay, bx, by, cx, cy;
void DFS(long long x, long long y) {
  if (x == cx && y == cy) {
    cout << "YES";
    check = 1;
    return;
  }
  danhdau[x * 10000 + y] = 1;
  if ((x + y == ax + ay) || (x - y == ax - ay) || (x == ax) || (y == ay))
    return;
  if (y < n && danhdau[x * 10000 + y + 1] == 0) DFS(x, y + 1);
  if (check == 1) return;
  if (x < n && danhdau[(x + 1) * 10000 + y] == 0) DFS(x + 1, y);
  if (check == 1) return;
  if (x > 1 && danhdau[(x - 1) * 10000 + y] == 0) DFS(x - 1, y);
  if (check == 1) return;
  if (y > 1 && danhdau[x * 10000 + y - 1] == 0) DFS(x, y - 1);
  if (check == 1) return;
  if (x > 1 && y < n && danhdau[(x - 1) * 10000 + y + 1] == 0)
    DFS(x - 1, y + 1);
  if (check == 1) return;
  if (x < n && y < n && danhdau[(x + 1) * 10000 + y + 1] == 0)
    DFS(x + 1, y + 1);
  if (check == 1) return;
  if (x > 1 && y > 1 && danhdau[(x - 1) * 10000 + y - 1] == 0)
    DFS(x - 1, y - 1);
  if (check == 1) return;
  if (x < n && y > 1 && danhdau[(x + 1) * 10000 + y - 1] == 0)
    DFS(x + 1, y - 1);
}
int main() {
  cin >> n;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;
  DFS(bx, by);
  if (check == 0) cout << "NO";
}
