#include <bits/stdc++.h>
using namespace std;
long long getS(long long n) {
  if (n == 1) return 0;
  n -= 1;
  long long r = 1, sz = 6;
  while (n > r * sz) {
    n -= r * sz;
    r++;
  }
  return r;
}
void solve(long long n) {
  if (n == 1) return;
  n -= 1;
  long long r = 1, sz = 6;
  while (n > sz) {
    n -= sz;
    sz += 6;
  }
  r = sz / 6;
  long long x = 1 + 2 * (r - 1), y = 2;
  long long side = r + 1;
  if (n > side - 1) {
    x -= 1 * (side - 2);
    y += 2 * (side - 2);
    n -= side - 1;
  } else {
    x -= 1 * (n - 1);
    y += 2 * (n - 1);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
  if (n > side - 1) {
    x -= 2 * (side - 1);
    y += 0 * (side - 1);
    n -= side - 1;
  } else {
    x -= 2 * (n);
    y += 0 * (n);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
  if (n > side - 1) {
    x -= 1 * (side - 1);
    y -= 2 * (side - 1);
    n -= side - 1;
  } else {
    x -= 1 * (n);
    y -= 2 * (n);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
  if (n > side - 1) {
    x += 1 * (side - 1);
    y -= 2 * (side - 1);
    n -= side - 1;
  } else {
    x += 1 * (n);
    y -= 2 * (n);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
  if (n > side - 1) {
    x += 2 * (side - 1);
    y -= 0 * (side - 1);
    n -= side - 1;
  } else {
    x += 2 * (n);
    y -= 0 * (n);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
  if (n > side - 1) {
    x += 1 * (side - 1);
    y += 2 * (side - 1);
    n -= side - 1;
  } else {
    x += 1 * (n);
    y += 2 * (n);
    n -= side - 1;
    cout << x << " " << y << endl;
    return;
  }
}
void solveAll(long long n) {
  long long s = getS(n);
  if (s == 0) {
    cout << "0 0" << endl;
  } else {
    solve(n);
  }
}
int main() {
  long long n;
  cin >> n;
  n++;
  solveAll(n);
}
