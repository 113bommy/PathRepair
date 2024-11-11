#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAXN = 2e5 + 5;
const int MAXM = 1e7;
const int N = 1e3 + 10;
const double EPS = 1e-5;
int i, j, k;
int n, m;
int kek[100][5];
int getId(char c) {
  if (isdigit(c)) return 0;
  if (islower(c)) return 1;
  if (c == '#' || c == '*' || c == '&') return 2;
  return 3;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string w[n];
  for (i = 0; i < n; i++) cin >> w[i];
  for (i = 0; i < 100; i++)
    for (j = 0; j < 5; j++) kek[i][j] = 1e5;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int h = getId(w[i][j]);
      kek[i][h] = min(kek[i][h], min(j, m - j));
    }
  }
  int ans = 1e9;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        if (i != j && j != k && i != k)
          ans = min(ans, kek[i][0] + kek[j][1] + kek[k][2]);
      }
    }
  }
  cout << ans;
  return 0;
}
