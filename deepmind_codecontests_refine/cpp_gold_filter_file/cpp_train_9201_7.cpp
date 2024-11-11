#include <bits/stdc++.h>
using namespace std;
int t, arr[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void gen(int n) {
  int i;
  queue<int> q;
  arr[200 + 0][200 + 0] = n;
  if (arr[200 + 0][200 + 0] >= 4) {
    q.push(0);
    q.push(0);
  }
  while (!q.empty()) {
    int xx = q.front();
    q.pop();
    int yy = q.front();
    q.pop();
    if (arr[200 + xx][200 + yy] < 4) continue;
    int add = (arr[200 + xx][200 + yy]) / 4;
    arr[200 + xx][200 + yy] %= 4;
    for (i = 0; i <= 3; i++) {
      arr[200 + xx + dx[i]][200 + yy + dy[i]] += add;
      if (arr[200 + xx + dx[i]][200 + yy + dy[i]] >= 4) {
        q.push(xx + dx[i]);
        q.push(yy + dy[i]);
      }
    }
  }
}
int main() {
  int x, y, n;
  cin >> n >> t;
  gen(n);
  while (t--) {
    cin >> x >> y;
    if (x < -200 || x > 200 || y < -200 || y > 200) {
      cout << 0 << "\n";
      continue;
    }
    cout << arr[200 + x][200 + y] << "\n";
  }
  return 0;
}
