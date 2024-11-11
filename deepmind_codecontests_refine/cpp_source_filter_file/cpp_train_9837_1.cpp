#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:133217728")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000007;
string c[111];
int n, m;
long long w[111][111];
long long need[101][101];
int main() {
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) {
    cin >> c[i];
    for (int j = (0); j < (m); ++j) {
      if (c[i][j] == 'W')
        need[i][j] = 1;
      else
        need[i][j] = 0;
      w[i][j] = 0;
    }
  }
  int sol = 0;
  for (int i = (n)-1; i >= (0); --i)
    for (int j = (m)-1; j >= (0); --j) {
      long long x = need[i][j] + w[i][j];
      if (x) {
        w[i][j] -= x;
        ++sol;
      }
      long long p = -w[i][j];
      if (i) w[i - 1][j] -= p;
      if (j) w[i][j - 1] -= p;
      if (i > 0 && j > 0) w[i - 1][j - 1] += p;
    }
  cout << sol << endl;
  return 0;
}
