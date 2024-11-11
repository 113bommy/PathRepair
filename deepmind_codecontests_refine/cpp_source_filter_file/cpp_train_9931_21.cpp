#include <bits/stdc++.h>
using namespace std;
const int NR = 1600 + 10;
const int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, num[NR][NR], init[NR][NR], tmp[NR][NR], mark[NR][NR],
    lightMark[NR][NR], corecnt = 0, ans[NR], belong;
void print(int (*arr)[NR]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << arr[i][j] << ' ';
    cout << endl;
  }
}
void pprint(int (*arr)[NR]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == 0)
        cout << 0 << ' ';
      else
        cout << mark[i][j] << ' ';
    }
    cout << endl;
  }
}
void delLight(int (*arr)[NR]) {
  memcpy(tmp, arr, sizeof(tmp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!arr[i + 1][j] || !arr[i - 1][j] || !arr[i][j + 1] || !arr[i][j - 1])
        tmp[i][j] = 0;
    }
  }
  memcpy(arr, tmp, sizeof(tmp));
}
void getLight(int (*arr)[NR], int (*initArr)[NR]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      initArr[i][j] -= arr[i][j];
      if (initArr[i][j] == -1) initArr[i][j] = 0;
    }
  }
}
void expandCore(int (*arr)[NR]) {
  memcpy(tmp, arr, sizeof(tmp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i + 1][j] || arr[i - 1][j] || arr[i][j + 1] || arr[i][j - 1])
        tmp[i][j] = 1;
    }
  }
  memcpy(arr, tmp, sizeof(tmp));
}
void dfsCore(int x, int y) {
  mark[x][y] = corecnt;
  for (int i = 0; i < 4; i++) {
    int newX = x + delta[i][0], newY = y + delta[i][1];
    if (newX < 0 || newX > n || newY < 0 || newY > m || mark[newX][newY] ||
        !num[newX][newY])
      continue;
    dfsCore(newX, newY);
  }
}
void dfsLight(int x, int y) {
  lightMark[x][y] = 1;
  if (mark[x][y] != 0) belong = mark[x][y];
  for (int i = 0; i < 4; i++) {
    int newX = x + delta[i][0], newY = y + delta[i][1];
    if (newX < 0 || newX > n || newY < 0 || newY > m || lightMark[newX][newY] ||
        !init[newX][newY])
      continue;
    dfsLight(newX, newY);
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> num[i][j];
  memcpy(init, num, sizeof(num));
  for (int i = 1; i <= 4; i++) delLight(num);
  for (int i = 1; i <= 7; i++) expandCore(num);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (num[i][j] && !mark[i][j]) {
        corecnt++;
        dfsCore(i, j);
      }
    }
  }
  getLight(num, init);
  for (int i = 1; i <= 1; i++) expandCore(init);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (init[i][j] && !lightMark[i][j]) {
        belong = 0;
        dfsLight(i, j);
        ans[belong]++;
      }
    }
  }
  sort(ans + 1, ans + corecnt + 1);
  cout << corecnt << endl;
  for (int i = 1; i <= corecnt; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
