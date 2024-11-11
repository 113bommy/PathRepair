#include <bits/stdc++.h>
using namespace std;
int a[2000005];
vector<int> b[2000005];
vector<int> c[2000005];
int main() {
  int x, y, i, j;
  cin >> x >> y;
  for (i = 1; i <= 1000; i++) {
    for (j = 1; j <= 1000; j++) {
      if (i == j) {
        continue;
      }
      a[i * i + j * j]++;
      b[i * i + j * j].push_back(i);
      c[i * i + j * j].push_back(j);
    }
  }
  x = x * x;
  y = y * y;
  if (a[x] == 0 || a[y] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (i = 0; i < a[x]; i++) {
    for (j = 0; j < a[y]; j++) {
      c[y][j] = -c[y][j];
      if ((b[x][i] * b[y][j] + c[x][i] * c[y][j]) == 0) {
        if (b[x][i] == b[y][j] || c[y][j] == c[x][i])
          b[y][j] *= -1, c[y][j] *= -1;
        cout << "YES" << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << b[x][i] << ' ' << c[x][i] << endl;
        cout << b[y][j] << ' ' << c[y][j] << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
