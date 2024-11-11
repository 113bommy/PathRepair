#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long modi) {
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % modi;
    b /= 2;
    a = (a * a) % modi;
  }
  return res;
}
int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
long long n, k, sum = 0, ans = 0, cur = 0;
int a, b, c, d;
int pos(string &x, char ch) {
  int i = 0;
  if (ch == '4')
    for (int i = 0; i < x.length(); i++)
      if (x[i] == ch) return i;
  for (i = x.length() - 1; i >= 0; i--) {
    if (x[i] == ch) return i;
  }
  return 0;
}
int main() {
  cin >> a >> b >> c >> d;
  if (abs(c - d) > 1) {
    cout << "-1";
    return 0;
  }
  string x, y;
  if (c == d) {
    int p = a, q = b;
    for (int i = 0; i < c; i++) {
      x += "47";
      p--;
      q--;
    }
    x += '4';
    p--;
    if (p >= 0 && q >= 0) {
      x.insert(pos(x, '4'), p, '4');
      x.insert(pos(x, '7') - 1, q, '7');
      cout << x;
      return 0;
    }
    p = a, q = b;
    for (int i = 0; i < c; i++) {
      y += "74";
      p--;
      q--;
    }
    y += '7';
    q--;
    if (p >= 0 && q >= 0) {
      y.insert(pos(y, '4'), p, '4');
      y.insert(pos(y, '7'), q, '7');
      cout << y;
      return 0;
    }
    cout << "-1";
  } else if (c < d) {
    int p = a, q = b;
    for (int i = 0; i < d; i++) {
      x += "74";
      p--;
      q--;
    }
    if (p >= 0 && q >= 0) {
      x.insert(pos(x, '4'), p, '4');
      x.insert(pos(x, '7'), q, '7');
      cout << x;
      return 0;
    }
    cout << "-1";
  } else {
    int p = a, q = b;
    for (int i = 0; i < c; i++) {
      x += "47";
      p--;
      q--;
    }
    if (p >= 0 && q >= 0) {
      x.insert(pos(x, '4'), p, '4');
      x.insert(pos(x, '7'), q, '7');
      cout << x;
      return 0;
    }
    cout << "-1";
  }
  return 0;
}
