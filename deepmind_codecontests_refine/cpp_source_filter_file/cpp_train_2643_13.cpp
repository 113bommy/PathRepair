#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-8;
const int maxn = 52;
const int maxk = 213;
const int mod = 1e9 + 7;
int d[maxk][maxn][maxn];
template <typename T>
void add(T &x, long long y) {
  y %= mod;
  x += y;
  while (x > mod) x -= mod;
}
long long c[maxn][maxn];
int main() {
  for (int i = 0; i < maxn; i++) c[0][i] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < maxn; j++) {
      add(c[i][j], c[i][j - 1]);
      add(c[i][j], c[i - 1][j - 1]);
    }
  int n, l;
  cin >> n >> l;
  int q1 = 0, q2 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x /= 50;
    if (x == 1)
      q1++;
    else
      q2++;
  }
  l /= 50;
  d[0][0][0] = 1;
  for (int k = 0; k < maxk - 1; k++) {
    if (k % 2 == 1) {
      if (d[k][q1][q2] != 0) {
        cout << k << endl;
        cout << d[k][q1][q2];
        return 0;
      }
      for (int i = 0; i <= q1; i++)
        for (int j = 0; j <= q2; j++)
          if (d[k][i][j] > 0) {
            for (int i1 = 0; i1 <= i; i1++)
              for (int j1 = 0; j1 <= j; j1++)
                if (i1 + j1 * 2 <= l && i1 + j1) {
                  add(d[k + 1][i - i1][j - j1],
                      d[k][i][j] * c[i1][i] * c[j1][j]);
                }
          }
      continue;
    }
    for (int i = 0; i <= q1; i++)
      for (int j = 0; j <= q2; j++)
        if (d[k][i][j] > 0) {
          for (int i1 = 0; i1 <= q1 - i; i1++)
            for (int j1 = 0; j1 <= q2 - j; j1++)
              if (i1 + j1 * 2 <= l && i1 + j1) {
                add(d[k + 1][i + i1][j + j1],
                    d[k][i][j] * c[i1][q1 - i] * c[j1][q2 - j]);
              }
        }
  }
  cout << "-1";
  cout << "0";
  return 0;
}
