#include <bits/stdc++.h>
using namespace std;
int main() {
  int R, C, K;
  while (cin >> R >> C >> K) {
    int a[R][C];
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) cin >> a[i][j];
    vector<int> vx, vy;
    for (int i = 0; i < C - 1; i++) {
      for (int j = i + 1; j < C; j++) {
        for (int k = 0; k < R; k++) {
          if (K == 0 && a[k][i] > a[k][j]) {
            int temp = a[k][i];
            a[k][i] = a[k][j];
            a[k][j] = a[k][i];
            vx.push_back(i + 1);
            vy.push_back(j + 1);
            break;
          } else if (K == 1 && a[k][i] < a[k][j]) {
            int temp = a[k][i];
            a[k][i] = a[k][j];
            a[k][j] = a[k][i];
            vx.push_back(j + 1);
            vy.push_back(i + 1);
            break;
          }
        }
      }
    }
    cout << vx.size() << endl;
    for (int i = 0; i < vx.size(); i++) cout << vx[i] << " " << vy[i] << endl;
  }
  return 0;
}
