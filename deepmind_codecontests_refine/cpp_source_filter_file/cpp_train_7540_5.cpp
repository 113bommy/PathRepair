#include <bits/stdc++.h>
using namespace std;
char arr[1002][2020];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (int i = 0; i < 1002; i++)
    for (int j = 0; j < 2005; j++) arr[i][j] = ' ';
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  bool f = 0;
  int x = 0, y = 1002, ma = 1e9, width = 0, mi = 0;
  for (int i = 0; i < n; i++) {
    width += vec[i];
    int ty = y;
    if (!f)
      ty -= (vec[i]);
    else
      ty += (vec[i]);
    ma = min(ma, ty);
    mi = max(mi, ty);
    while (y != ty) {
      if (!f) {
        arr[x][y] = '/';
        y--;
      } else {
        arr[x][y] = '\\';
        y++;
      }
      x++;
    }
    if (!f)
      y++;
    else
      y--;
    f = !f;
  }
  for (int i = ma + 1; i <= mi; i++) {
    bool flag = 0;
    for (int j = 0; j < width; j++) {
      if (arr[j][i] == '/' || arr[j][i] == '\\') {
        flag = 1;
        break;
      }
    }
    if (!flag) return 0;
    for (int j = 0; j < width; j++) {
      cout << arr[j][i];
    }
    cout << endl;
  }
  return 0;
}
