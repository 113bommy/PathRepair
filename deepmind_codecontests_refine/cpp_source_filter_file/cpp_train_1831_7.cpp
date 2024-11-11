#include <bits/stdc++.h>
const int N = 125;
using namespace std;
int a[N][5], num[5];
int n;
int getmaxpoint(int all, int sov) {
  double x = 1.0 * sov / all;
  if (x > 0.5 && x <= 1) return 500;
  if (x > 0.25 && x <= 0.5) return 1000;
  if (x > 1.0 / 8 && x <= 0.25) return 1500;
  if (x > 1.0 / 16 && x <= 1.0 / 8) return 2000;
  if (x > 1.0 / 32 && x <= 1.0 / 16) return 2500;
  return 3000;
}
int getscore(bool isv, int add, int j) {
  int po;
  if (isv) {
    if (a[1][j] == -1) return 0;
    if (a[2][j] == -1) po = getmaxpoint(add + n, num[j]);
    if (a[1][j] <= a[2][j] || a[2][j] == -1)
      po = getmaxpoint(add + n, num[j]);
    else
      po = getmaxpoint(add + n, add + num[j]);
    return po * (1 - a[1][j] / 250.0);
  } else {
    if (a[2][j] == -1) return 0;
    if (a[1][j] == -1) po = getmaxpoint(add + n, add + num[j]);
    if (a[1][j] <= a[2][j] || a[2][j] == -1)
      po = getmaxpoint(add + n, num[j]);
    else
      po = getmaxpoint(add + n, add + num[j]);
    return po * (1 - a[2][j] / 250.0);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] != -1) num[j]++;
    }
  }
  for (int add = 0; add < 33 * N; add++) {
    int p = 0, v = 0;
    for (int i = 0; i < 5; i++) {
      int x = getscore(true, add, i);
      v += x;
    }
    for (int i = 0; i < 5; i++) {
      int x = getscore(false, add, i);
      p += x;
    }
    if (v >= p) {
      cout << add << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
