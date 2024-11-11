#include <bits/stdc++.h>
using namespace std;
const int Maxn = 20;
long long n, d[2 * Maxn][Maxn], tvn[Maxn];
bool par[2 * Maxn][Maxn];
string s, ans;
void pp(int i, int j) {
  if (i == 0) return;
  if (par[i][j]) {
    ans += 'H';
    pp(i - 1, j - 1);
  } else {
    ans += 'M';
    pp(i - 1, j);
  }
}
int main() {
  cin >> n >> s;
  tvn[0] = 1;
  for (int i = 1; i < n; i++) tvn[i] = tvn[i - 1] * 10;
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j < n; j++) d[i][j] = -1;
  d[1][1] = (s[0] - '0') * tvn[n - 1];
  par[1][1] = 1;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 1; j <= min(i, 18); j++) {
      if (d[i - 1][j - 1] + (s[i - 1] - '0') * tvn[n - j] != -1 &&
          d[i - 1][j - 1] + (s[i - 1] - '0') * tvn[n - j] >
              d[i - 1][j] + (s[i - 1] - '0') * tvn[n - (i - j)]) {
        d[i][j] = d[i - 1][j - 1] + (s[i - 1] - '0') * tvn[n - j];
        par[i][j] = 1;
      } else {
        d[i][j] = d[i - 1][j] + (s[i - 1] - '0') * tvn[n - (i - j)];
      }
    }
  }
  pp(2 * n, n);
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
