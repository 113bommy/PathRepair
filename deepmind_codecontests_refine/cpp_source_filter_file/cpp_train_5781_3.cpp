#include <bits/stdc++.h>
const long long oo = 1e9;
using namespace std;
int m, d, dem;
long long res1, res2, f[2010][2010];
string x, y;
long long dq(int i, int du) {
  if (i > dem) {
    if (du == 0) return 1;
    return 0;
  }
  if (f[i][du] != -1) return f[i][du];
  long long ans = 0;
  if (i % 2 == 0)
    ans = dq(i + 1, (du * 10 + d) % m);
  else {
    for (int j = 0; j < 10; j++)
      if (j != d) ans = (ans + dq(i + 1, (du * 10 + j) % m)) % oo;
  }
  return f[i][du] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> d;
  cin >> x >> y;
  x = " " + x;
  y = " " + y;
  dem = x.length() - 1;
  int du = 0;
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= dem; i++) {
    if (i % 2 == 0) {
      if (x[i] - 48 < d)
        break;
      else if (x[i] - 48 == d)
        du = (du * 10 + d) % m;
      else {
        res1 = (res1 + dq(i + 1, (du * 10 + d) % m)) % oo;
        break;
      }
    } else {
      if (i > 1) {
        for (int j = 0; j < x[i] - 48; j++)
          if (j != d) res1 = (res1 + dq(i + 1, (du * 10 + j) % m)) % oo;
      } else {
        for (int j = 1; j < x[i] - 48; j++)
          if (j != d) res1 = (res1 + dq(i + 1, (du * 10 + j) % m)) % oo;
      }
      if (x[i] - 48 == d) break;
      du = (du * 10 + x[i] - 48) % m;
    }
  }
  dem = y.length() - 1;
  du = 0;
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= dem; i++) {
    if (i % 2 == 0) {
      if (y[i] - 48 < d)
        break;
      else if (y[i] - 48 == d)
        du = (du * 10 + d) % m;
      else {
        res2 = (res2 + dq(i + 1, (du * 10 + d) % m)) % oo;
        break;
      }
    } else {
      if (i > 1) {
        for (int j = 0; j < y[i] - 48; j++)
          if (j != d) res2 = (res2 + dq(i + 1, (du * 10 + j) % m)) % oo;
      } else {
        for (int j = 1; j < y[i] - 48; j++)
          if (j != d) res2 = (res2 + dq(i + 1, (du * 10 + j) % m)) % oo;
      }
      if (y[i] - 48 == d) break;
      du = (du * 10 + y[i] - 48) % m;
    }
  }
  bool ok = 0;
  du = 0;
  for (int i = 1; i < y.length(); i++) {
    if (i % 2 == 0 && y[i] - 48 != d) {
      ok = 1;
      break;
    } else if (i % 2 == 1 && y[i] - 48 == d) {
      ok = 1;
      break;
    }
    du = (du * 10 + y[i] - 48) % m;
  }
  if (!ok && du == 0) res2++;
  cout << (res2 - res1 + oo) % oo;
  return 0;
}
