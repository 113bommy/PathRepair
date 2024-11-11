#include <bits/stdc++.h>
const long double eps = 1e-9;
const long double LDINF = 1e70;
const long long LINF = 1ll << 60;
const int INF = 1 << 30;
const long double pi = fabs(atan2(0.0, -1.0));
using namespace std;
int n, a[1010];
int dp[1010][2013];
int p[1010][2013];
int pw[5];
vector<int> res;
void Load() {
  cin >> n;
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  pw[0] = 1;
  pw[1] = 10;
  pw[2] = 100;
  pw[3] = 1000;
  pw[4] = 10000;
}
inline int number(int a, int k, int o) {
  return ((a / pw[k + 1]) * pw[1] + o) * pw[k] + a % pw[k];
}
void Solve() {
  int i, j, k, o;
  int t;
  dp[0][1000] = 1;
  for (i = 0; i < n; i++) {
    for (j = 1000; j <= 2011; j++) {
      if (dp[i][j] == 0) continue;
      for (k = 0; k < 4; k++) {
        for (o = 0; o < 9; o++) {
          t = number(a[i], k, o);
          if (t >= j && t <= 2011) {
            dp[i + 1][t] = 1;
            p[i + 1][t] = j;
          }
        }
      }
    }
  }
  for (i = 1000; i <= 2011; i++) {
    if (dp[n][i]) {
      break;
    }
  }
  if (i == 2012) {
    cout << "No solution";
    return;
  }
  j = i;
  i = n;
  while (i != 0) {
    res.push_back(j);
    j = p[i][j];
    i--;
  }
  for (i = res.size() - 1; i >= 0; i--) printf("%d\n", res[i]);
}
int main() {
  Load();
  Solve();
  return 0;
}
