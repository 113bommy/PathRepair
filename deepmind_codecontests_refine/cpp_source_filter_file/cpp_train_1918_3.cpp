#include <bits/stdc++.h>
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;
int abs(int x) {
  if (x >= 0)
    return x;
  else
    return -x;
}
int main() {
  long long n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;
  long long dx1 = i - 1, dy1 = j - 1, dx2 = n - i, dy2 = j - 1, dx3 = n - i,
            dy3 = m - j, dx4 = i - 1, dy4 = m - j;
  long long s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  int ok = 0, ok1 = 0;
  a = abs(a);
  b = abs(b);
  while (dx1 >= a && dy1 >= b) {
    dx1 -= a;
    dy1 -= b;
    s1++;
    if (dx1 == 1 && dy1 == 1) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    if ((j + b <= m) || (j - b >= 1)) {
      while (dx1 >= 2 * a) {
        dx1 -= 2 * a;
        s1 += 2;
      }
    }
    if ((i + a <= n) || (i - a >= 1)) {
      while (dy1 >= 2 * b) {
        dy1 -= 2 * b;
        s1 += 2;
      }
    }
  }
  if (dx1 == 0 && dy1 == 0) {
  } else {
    s1 = INF;
  }
  ok = 0;
  ok1 = 0;
  while (dx2 >= a && dy2 >= b) {
    dx2 -= a;
    dy2 -= b;
    s2++;
    if (dx2 == 0 && dy2 == 0) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    if ((j + b <= m) || (j - b >= 1)) {
      while (dx2 >= 2 * a) {
        dx2 -= 2 * a;
        s2 += 2;
      }
    }
    if ((i + a <= n) || (i - a >= 1)) {
      while (dy2 >= 2 * b) {
        dy2 -= 2 * b;
        s2 += 2;
      }
    }
  }
  if (dx2 == 0 && dy2 == 0) {
  } else {
    s2 = INF;
  }
  ok = 0;
  ok1 = 0;
  while (dx3 >= a && dy3 >= b) {
    dx3 -= a;
    dy3 -= b;
    s3++;
    if (dx3 == 0 && dy3 == 0) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    if ((j + b <= m) || (j - b >= 1)) {
      while (dx3 >= 2 * a) {
        dx3 -= 2 * a;
        s3 += 2;
      }
    }
    if ((i + a <= n) || (i - a >= 1)) {
      while (dy3 >= 2 * b) {
        dy3 -= 2 * b;
        s3 += 2;
      }
    }
  }
  if (dx3 == 0 && dy3 == 0) {
  } else {
    s3 = INF;
  }
  ok = 0;
  ok1 = 0;
  while (dx4 >= a && dy4 >= b) {
    dx4 -= a;
    dy4 -= b;
    s4++;
    if (dx4 == 0 && dy4 == 0) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    if ((j + b <= m) || (j - b >= 1)) {
      while (dx4 >= 2 * a) {
        dx4 -= 2 * a;
        s4 += 2;
      }
    }
    if ((i + a <= n) || (i - a >= 1)) {
      while (dy4 >= 2 * b) {
        dy4 -= 2 * b;
        s4 += 2;
      }
    }
  }
  if (dx4 == 0 && dy4 == 0) {
  } else {
    s4 = INF;
  }
  long long re = min(s4, min(s3, min(s2, s1)));
  if (re == INF)
    cout << "Poor Inna and pony!" << endl;
  else
    cout << re << endl;
}
