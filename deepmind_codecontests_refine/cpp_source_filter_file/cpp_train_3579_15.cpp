#include <bits/stdc++.h>
using namespace std;
bool exitInput = false;
int ntest = 1, itest = 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const long long Mod = 1000000007LL;
const int maxn = 100000 + 5;
const int maxv = 3000 + 5;
const int maxe = 2 * 400 + 5;
int f[300][300];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(6);
  cout << fixed;
  int n;
  int a, b, c;
  cin >> n;
  if (n == 1) {
    cin >> a;
    if (a == 0)
      puts("BitLGM");
    else
      puts("BitAryo");
  } else if (n == 3) {
    cin >> a >> b >> c;
    a = a ^ b ^ c;
    if (a == 0)
      puts("BitAryo");
    else
      puts("BitLGM");
  } else {
    cin >> a >> b;
    f[0][0] = 0;
    for (int x = 1; x < 300; ++x) {
      f[x][0] = f[0][x] = 1;
    }
    for (int x = 1; x < 300; ++x) {
      for (int y = 1; y < 300; ++y) {
        for (int k = 1; k <= x; ++k) {
          if (f[x - k][y] == 0) f[x][y] = 1;
        }
        for (int k = 1; k <= y; ++k) {
          if (f[x][y - k] == 0) f[x][y] = 1;
        }
        for (int k = 1; k <= x && k <= y; ++k) {
          if (f[x - k][y - k] == 0) {
            f[x][y] = 1;
          }
        }
      }
    }
    if (f[a][b] == 1)
      puts("BitLGM");
    else
      puts("BitAryo");
  }
  return 0;
}
