#include <bits/stdc++.h>
const long long INF32 = 1e9;
const long long INF64 = 1e17;
const int RANGE = 1e6 + 5;
using namespace std;
template <class T>
void read(T &Val) {
  T tmp = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    tmp = tmp * 10 + ch - '0';
    ch = getchar();
  }
  Val = flag * tmp;
}
int q, cnt;
int n, m;
char data[300][300];
int bigX[] = {0, 1, -1, 0, 1, -1, 1, -1}, bigY[] = {1, 0, 0, -1, 1, -1, -1, 1};
void check(int x, int y) {
  if (x < 0 or y < 0 or x >= m or y >= n or data[y][x] != '1') return;
  data[y][x] = '2';
  cnt++;
  for (int i = 0; i < 8; i++) check(x + bigX[i], y + bigY[i]);
}
int tell_square(int y, int x, int d) {
  int yy = y + d, xx = x + d;
  if (yy >= n or xx >= m) return 0;
  for (int i = x; i <= xx; i++) {
    if (data[y][i] != '2' or data[yy][i] != '2') return 0;
  }
  for (int i = y; i <= yy; i++) {
    if (data[i][x] != '2' or data[i][xx] != '2') return 0;
  }
  return 1;
}
int tell_rombus(int y, int x, int d) {
  int yy = y + d * 2, lxx = x - d, rxx = x + d;
  if (yy >= n or rxx >= m or lxx < 0) return 0;
  for (int i = 0; i <= d; i++) {
    if (data[y + i][x + i] != '2' or data[y + i + d][x + i - d] != '2') {
      return 0;
    }
  }
  for (int i = 0; i <= d; i++) {
    if (data[y + i][x - i] != '2' or data[y + i + d][x - i + d] != '2') {
      return 0;
    }
  }
  return 1;
}
int main() {
  read(q);
  while (q--) {
    read(n), read(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> data[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (data[i][j] == '0' or data[i][j] == '2') continue;
        cnt = 0;
        check(j, i);
        if ((cnt % 4) != 0 or cnt / 4 > 250) continue;
        ans = ans + tell_rombus(i, j, cnt / 4) + tell_square(i, j, cnt / 4);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
