#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int f(int x, int y) { cout << x << ' ' << y << endl; }
int dx[] = {3, 2, 3, 0, 1, 2, 1, 1, 3, 3, 0, 0, 2, 2, 1, 0};
int dy[] = {2, 2, 1, 1, 3, 3, 2, 1, 0, 3, 2, 3, 0, 1, 0, 0};
int n;
int main() {
  cin >> n;
  if ((n * (n - 1) / 2) & 1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (n % 4 == 0) {
    for (int i = 1; i < n; i += 4) {
      f(i + 2, i + 3);
      f(i, i + 2);
      f(i + 1, i + 3);
      f(i + 1, i + 2);
      f(i, i + 3);
      f(i, i + 1);
    }
    for (int i = 1; i < n; i += 4) {
      for (int j = i + 4; j < n; j += 4) {
        for (int k = 0; k < 16; k++) f(i + dx[k], j + dy[k]);
      }
    }
  } else {
    for (int i = 1; i < n; i += 4) {
      f(i + 2, n);
      f(i + 2, i + 3);
      f(i + 3, n);
      f(i, i + 2);
      f(i + 1, i + 3);
      f(i + 1, i + 2);
      f(i, i + 3);
      f(i, n);
      f(i, i + 1);
      f(i + 1, n);
    }
    for (int i = 1; i < n; i += 4) {
      for (int j = i + 4; j < n; j += 4) {
        for (int k = 0; k < 16; k++) f(i + dx[k], j + dy[k]);
      }
    }
  }
  return 0;
}
