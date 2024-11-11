#include <bits/stdc++.h>
using namespace std;
int sg[110][3][3];
struct node {
  int x, y;
};
bool cmp(node p, node q) { return p.x < q.x; }
int get_sg(int len, int x, int y) {
  if (sg[len][x][y] != -1) return sg[len][x][y];
  if (len == 0) return sg[len][x][y] = sg[len][y][x] = 0;
  if (x > y) swap(x, y);
  if (len == 1 && x == 1 && y == 2) return sg[len][x][y] = sg[len][y][x] = 0;
  if (len == 1) return sg[len][x][y] = sg[len][y][x] = 1;
  bool vs[110];
  memset(vs, 0, sizeof vs);
  for (int len1 = 0; len1 < len; len1++) {
    int len2 = len - 1 - len1;
    if (len1 == 0) {
      if (x == 0) {
        vs[get_sg(len2, 1, y)] = 1;
        vs[get_sg(len2, 2, y)] = 1;
      } else
        vs[get_sg(len2, x, y)] = 1;
    } else if (len2 == 0) {
      if (y == 0) {
        vs[get_sg(len1, x, 1)] = 1;
        vs[get_sg(len1, x, 2)] = 1;
      } else
        vs[get_sg(len1, x, y)] = 1;
    } else {
      vs[get_sg(len1, x, 1) ^ get_sg(len2, 1, y)] = 1;
      vs[get_sg(len1, x, 2) ^ get_sg(len2, 2, y)] = 1;
    }
  }
  for (int i = 0; i < 110; i++)
    if (!vs[i]) return sg[len][x][y] = sg[len][y][x] = i;
}
node arr[110];
int main() {
  memset(sg, -1, sizeof(sg));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i].x >> arr[i].y;
  }
  sort(arr, arr + m, cmp);
  int result = 0;
  result ^= get_sg(arr[0].x - 1, 0, arr[0].y);
  for (int i = 1; i < m; i++) {
    result ^= get_sg(arr[i].x - arr[i - 1].x - 1, arr[i].y, arr[i - 1].y);
  }
  result ^= get_sg(n - arr[m - 1].x, 0, arr[m - 1].y);
  if (result) {
    cout << "WIN\n";
  } else {
    cout << "LOSE\n";
  }
  return 0;
}
