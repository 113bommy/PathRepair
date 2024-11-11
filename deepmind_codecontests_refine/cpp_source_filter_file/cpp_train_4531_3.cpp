#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, -1, -2, -1, 1, 2, 1};
const int dy[] = {0, 2, 0, -2, -2, 0, 2};
inline long long CB(long long n) {
  long long st = 1, dr = 1000000000, mij, sol;
  while (st <= dr) {
    mij = ((st + dr) >> 1);
    if (1LL * mij * (mij + 1) >= n) {
      sol = mij;
      dr = mij - 1;
    } else
      st = mij + 1;
  }
  return mij;
}
int main() {
  int i, j, dir;
  long long n;
  cin.sync_with_stdio(0);
  cin >> n;
  if (!n)
    cout << "0 0";
  else {
    long long cn = n / 3;
    if (n % 3) ++cn;
    long long k = CB(cn);
    long long x = 2 * k - 1, y = 2;
    n -= 3LL * (k - 1) * k + 1;
    if (n < k)
      dir = 1;
    else {
      dir = 2;
      n -= k - 1;
      x += (k - 1) * dx[1];
      y += (k - 1) * dy[1];
      while (n > k) {
        ++dir;
        n -= k;
        x += k * dx[dir - 1];
        y += k * dy[dir - 1];
      }
    }
    cout << x + dx[dir] * n << " " << y + dy[dir] * n << "\n";
  }
  return 0;
}
