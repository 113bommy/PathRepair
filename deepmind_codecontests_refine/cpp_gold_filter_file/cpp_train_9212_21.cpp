#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
const int N = 200005;
const double eps = 1e-9;
char ar[1234][1234];
int x;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (sqrt(a * b + c * d + e * f) * sqrt(a * b + c * d + e * f) ==
      a * b + c * d + e * f)
    x = (int)(sqrt(a * b + c * d + e * f));
  else
    cout << -1, exit(0);
  if (x < a || x < b || x < c || x < d || x < e || x < f) cout << -1, exit(0);
  for (int i = 1; i <= x; ++i)
    for (int j = 1; j <= x; ++j) ar[i][j] = 'D';
  if (a == x) {
    for (int i = 1; i <= b; ++i)
      for (int j = 1; j <= a; ++j) ar[i][j] = 'A';
  } else if (b == x) {
    for (int i = 1; i <= a; ++i)
      for (int j = 1; j <= b; ++j) ar[i][j] = 'A';
  }
  int p = 1;
  if (c == x) {
    for (int i = 1; i <= x; ++i) {
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    }
    for (int i = p; i <= p + d - 1; ++i)
      for (int j = 1; j <= c; ++j) ar[i][j] = 'B';
  } else if (d == x) {
    for (int i = 1; i <= x; ++i) {
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    }
    for (int i = p; i <= p + c - 1; ++i)
      for (int j = 1; j <= d; ++j) ar[i][j] = 'B';
  }
  if (e == x) {
    for (int i = 1; i <= x; ++i) {
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    }
    for (int i = p; i <= p + f - 1; ++i)
      for (int j = 1; j <= e; ++j) ar[i][j] = 'C';
  } else if (f == x) {
    for (int i = 1; i <= x; ++i) {
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    }
    for (int i = p; i <= p + e - 1; ++i)
      for (int j = 1; j <= f; ++j) ar[i][j] = 'C';
  }
  for (int i = 1; i <= x; ++i)
    if (ar[i][1] == 'D') {
      p = i;
      break;
    }
  if (a != x && b != x) {
    if (a + p - 1 == x)
      for (int i = p; i <= a + p - 1; ++i)
        for (int j = 1; j <= b; ++j) ar[i][j] = 'A';
    else if (b + p - 1 == x) {
      for (int i = p; i <= b + p - 1; ++i)
        for (int j = 1; j <= a; ++j) ar[i][j] = 'A';
    }
  }
  int q = 1;
  for (int i = 1; i <= x; ++i)
    if (ar[p][i] == 'D') {
      q = i;
      break;
    }
  if (c != x && d != x) {
    for (int i = 1; i <= x; ++i)
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    if (c + p - 1 == x)
      for (int i = p; i <= c + p - 1; ++i)
        for (int j = q; j <= d + q - 1; ++j) ar[i][j] = 'B';
    else if (d + p - 1 == x) {
      for (int i = p; i <= d + p - 1; ++i)
        for (int j = q; j <= c + q - 1; ++j) ar[i][j] = 'B';
    }
  }
  if (e != x && f != x) {
    for (int i = 1; i <= x; ++i)
      if (ar[i][1] == 'D') {
        p = i;
        break;
      }
    for (int i = 1; i <= x; ++i)
      if (ar[p][i] == 'D') {
        q = i;
        break;
      }
    if (e + p - 1 == x)
      for (int i = p; i <= e + p - 1; ++i)
        for (int j = q; j <= f + q - 1; ++j) ar[i][j] = 'C';
    else if (f + p - 1 == x) {
      for (int i = p; i <= f + p - 1; ++i)
        for (int j = q; j <= e + q - 1; ++j) ar[i][j] = 'C';
    }
  }
  for (int i = 1; i <= x; ++i)
    for (int j = 1; j <= x; ++j)
      if (ar[i][j] == 'D') cout << -1, exit(0);
  cout << x << endl;
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= x; ++j) cout << ar[i][j];
    cout << endl;
  }
  return 0;
}
