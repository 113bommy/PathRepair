#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:127108864")
const double eps = 1e-9;
const long long inf = 21474836479999;
const int maxn = 100010;
int main() {
  cin.sync_with_stdio(0);
  int n, m, sum, count, k;
  char a[4][11];
  string ans[6];
  cin >> k;
  for (int i = 0; i < 6; ++i) ans[i] = "";
  for (int i = 0; i < 11; ++i)
    for (int j = 0; j < 4; ++j) a[j][i] = '.';
  for (int i = 0; i < 11; ++i)
    for (int j = 0; j < 4; ++j) {
      if (i == 0) {
        if (k > 0) {
          a[j][i] = 'O';
          --k;
        } else {
          a[j][i] = '#';
        }
      } else {
        if (j == 2) ++j;
        if (k > 0) {
          a[j][i] = 'O';
          --k;
        } else {
          a[j][i] = '#';
        }
      }
    }
  ans[0] = "+------------------------+\n";
  for (int i = 1; i < 5; ++i) ans[i] = "|";
  for (int i = 1; i < 6; ++i) {
    for (int x = 0; x < 11; ++x) {
      ans[i] += a[i - 1][x];
      ans[i] += '.';
    }
  }
  ans[1] += "|D|)\n";
  ans[2] += "|.|\n";
  ans[3] += "..|\n";
  ans[4] += "|.|)\n";
  ans[5] = "+------------------------+";
  for (int i = 0; i < 6; ++i) cout << ans[i];
  return 0;
}
