#include <bits/stdc++.h>
long long max(long long x, long long y) { return (x > y ? x : y); }
long long min(long long x, long long y) { return (x < y ? x : y); }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
using namespace ::std;
const long long maxn = 210;
const long long inf = 1e17 + 800;
const long long mod = 1e9 + 7;
char e[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a, b, c, t = 0;
  cin >> a >> b >> c;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a != 0) {
        e[i * 2][j * 2] = '#';
        e[i * 2 + 1][j * 2] = '#';
        e[i * 2][j * 2 + 1] = '#';
        e[i * 2 + 1][j * 2 + 1] = '#';
        a--;
      } else {
        t++;
        if (t <= m) {
          if (j == 0) {
            if (t % 2 == m % 2) {
              e[2 * i][2 * j] = '#';
              e[2 * i + 1][2 * j] = '/';
              e[2 * i][2 * j + 1] = '/';
              e[2 * i + 1][2 * j + 1] = '.';
              c--;
            } else {
              e[2 * i][2 * j] = '\\';
              e[2 * i + 1][2 * j] = '.';
              e[2 * i][2 * j + 1] = '#';
              e[2 * i + 1][2 * j + 1] = '\\';
              c--;
            }
          } else {
            if (e[i * 2][2 * (j - 1) + 1] == '#') {
              e[2 * i][2 * j] = '#';
              e[2 * i + 1][2 * j] = '/';
              e[2 * i][2 * j + 1] = '/';
              e[2 * i + 1][2 * j + 1] = '.';
              c--;
            } else {
              e[2 * i][2 * j] = '\\';
              e[2 * i + 1][2 * j] = '.';
              e[2 * i][2 * j + 1] = '#';
              e[2 * i + 1][2 * j + 1] = '\\';
              c--;
            }
          }
        } else {
          if (b == 0) {
            char bala;
            char chap;
            if (i == 0 || e[2 * i - 1][2 * j] == '#' ||
                e[2 * i - 1][2 * j + 1] == '#') {
              bala = '#';
            } else {
              bala = '.';
            }
            if (j == 0 || e[2 * i][2 * j - 1] == '#' ||
                e[2 * i + 1][2 * j - 1] == '#') {
              chap = '#';
            } else {
              chap = '.';
            }
            if (bala == '#' && chap == '#') {
              e[2 * i][2 * j] = '#';
              e[2 * i + 1][2 * j] = '/';
              e[2 * i][2 * j + 1] = '/';
              e[2 * i + 1][2 * j + 1] = '.';
            }
            if (bala == '.' && chap == '#') {
              e[2 * i][2 * j] = '\\';
              e[2 * i + 1][2 * j] = '#';
              e[2 * i][2 * j + 1] = '.';
              e[2 * i + 1][2 * j + 1] = '\\';
            }
            if (bala == '#' && chap == '.') {
              e[2 * i][2 * j] = '\\';
              e[2 * i + 1][2 * j] = '.';
              e[2 * i][2 * j + 1] = '#';
              e[2 * i + 1][2 * j + 1] = '\\';
            }
            if (bala == '.' && chap == '.') {
              e[2 * i][2 * j] = '.';
              e[2 * i + 1][2 * j] = '/';
              e[2 * i][2 * j + 1] = '/';
              e[2 * i + 1][2 * j + 1] = '#';
            }
            c--;
          } else {
            e[i * 2][j * 2] = '.';
            e[i * 2 + 1][j * 2] = '.';
            e[i * 2][j * 2 + 1] = '.';
            e[i * 2 + 1][j * 2 + 1] = '.';
            b--;
          }
        }
      }
    }
  }
  for (long long i = 0; i < 2 * n; i++) {
    for (long long j = 0; j < 2 * m; j++) {
      cout << e[i][j];
    }
    cout << endl;
  }
}
