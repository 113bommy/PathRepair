#include <bits/stdc++.h>
using namespace std;
const bool print = false;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int const N = 1e5 + 9;
int n, m, k;
char c[6][22];
int solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int x = 5, y = 20;
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 20; j++) {
      c[i][j] = '%';
      if (i * j >= n) umin(x, i);
    }
  for (int j = 1; j <= 20; j++)
    if (x * j >= n) {
      y = j;
      break;
    }
  cout << x << ' ' << y << endl;
  int cnt = x * y - n;
  int X = cnt / x;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= X; j++) c[i][j] = '*';
  for (int j = 1; j <= cnt % x; j++) c[j][X + 1] = '*';
  for (int i = 1, id = 0; i <= x; i++) {
    for (int j = 1; j <= y; j++)
      if (c[i][j] == '%')
        cout << s[id++];
      else
        cout << '*';
    cout << endl;
  }
  return 0;
  for (int i = 0; i < 4; i++)
    if (ceil((n + 0.0) / (i + 1)) <= 20) {
      int x = i + 1;
      int y = ceil((n + 0.0) / x);
      int cnt = x * y - n;
      int rcnt = cnt / x, ycnt = cnt % x;
      cout << x << ' ' << y << endl;
      for (int a = 0, k = 0; a < x; a++) {
        int q = 0;
        if (ycnt > 0) q = 1;
        ycnt--;
        for (int b = 0; b < y; b++) {
          if (b < rcnt) {
            cout << '*';
            continue;
          }
          if (q > 0) {
            q = 0;
            cout << '*';
            continue;
          }
          cout << s[k++];
        }
        cout << endl;
      }
      return 0;
    }
  return 0;
}
void preprocess() {}
int main() {
  preprocess();
  int t = 1;
  while (t--) {
    solve();
  }
}
