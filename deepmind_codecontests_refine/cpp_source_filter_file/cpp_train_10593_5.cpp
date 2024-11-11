#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j;
  vector<long long> a(8);
  vector<long long> b(8);
  for (i = 0; i < 8; i++) cin >> a[i];
  a.push_back(a[0]);
  a.push_back(a[1]);
  for (i = 0; i < 8; i++) cin >> b[i];
  b.push_back(b[0]);
  b.push_back(b[1]);
  for (i = 0; i < a.size(); i++) a[i] += 100;
  for (i = 0; i < a.size(); i++) b[i] += 100;
  vector<long long> tmp1;
  for (i = 0; i < 8; i += 2) tmp1.push_back(a[i]);
  sort(tmp1.begin(), tmp1.end());
  long long X1 = tmp1.front(), X2 = tmp1.back();
  vector<long long> tmp2;
  for (i = 0; i < 8; i += 2) tmp2.push_back(a[i]);
  sort(tmp2.begin(), tmp2.end());
  long long Y1 = tmp2.front(), Y2 = tmp2.back();
  long long g[201][201] = {0};
  for (i = 0; i < 8; i += 2) {
    long long x1 = b[i], y1 = b[i + 1], x2 = b[i + 2], y2 = b[i + 3];
    long long dx, dy;
    if (x2 > x1)
      dx = 1;
    else
      dx = -1;
    if (y2 > y1)
      dy = 1;
    else
      dy = -1;
    long long x = x1, y = y1;
    while (x != x2) {
      g[x][y]++;
      x += dx, y += dy;
    }
  }
  for (i = 0; i <= 200; i++) {
    long long f = 0;
    long long p1, p2;
    for (j = 0; j <= 200; j++) {
      if (g[i][j] == 1) {
        p1 = j;
        f = 1;
        break;
      }
    }
    for (j = 200; j >= 0; j--) {
      if (g[i][j] == 1) {
        p2 = j;
        break;
      }
    }
    if (f == 1)
      for (j = p1; j <= p2; j++) g[i][j] = 1;
  }
  for (i = X1; i <= X2; i++)
    for (j = Y1; j <= Y2; j++) g[i][j]++;
  for (i = 0; i <= 200; i++) {
    for (j = 0; j <= 200; j++) {
      if (g[i][j] == 2) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
