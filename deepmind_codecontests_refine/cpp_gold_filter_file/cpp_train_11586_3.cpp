#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int N = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
int n, m, k;
int win[111];
char a[111][111];
int cnt[10];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int all = 0;
  int free_r = 0;
  int free_g = 0;
  for (int i = 1; i <= n; i++) {
    int r = 0, g = 0;
    bool isfull = 1;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'R') r = j;
      if (a[i][j] == 'G') g = j;
      if (a[i][j] == '-') isfull = 0;
    }
    if (r * g == 0 && !isfull) {
      if (r) free_r = 1;
      if (g) free_g = 1;
    }
    if (r && g) {
      int d = abs(r - g) - 1;
      for (int i = 0; i < 10; i++) {
        if ((d >> i) & 1) cnt[i]++;
      }
    }
  }
  if (free_r && free_g) {
    cout << "Draw";
    return 0;
  }
  if (free_r) {
    cout << "Second";
    return 0;
  }
  if (free_g) {
    cout << "First";
    return 0;
  }
  for (int i = 0; i < 10; i++) {
    if (cnt[i] % (k + 1) != 0) {
      cout << "First";
      return 0;
    }
  }
  cout << "Second";
  return 0;
}
