#include <bits/stdc++.h>
using namespace std;
int n;
string s, ans;
long long d[19][19] = {};
long long mul[18] = {};
int pre[19][19];
int main() {
  cin >> n >> s;
  mul[0] = 1;
  for (int i = 1; i < 18; ++i) mul[i] = mul[i - 1] * 10;
  for (int i = 0; i < (int)(n + 1); ++i)
    for (int j = 0; j < (int)(n + 1); ++j) {
      if (i < n) {
        if (d[i + 1][j] <= d[i][j] + (s[i + j] - '0') * mul[n - 1 - i]) {
          d[i + 1][j] = d[i][j] + (s[i + j] - '0') * mul[n - 1 - i];
          pre[i + 1][j] = 0;
        }
      }
      if (j < n) {
        if (d[i][j + 1] <= d[i][j] + (s[i + j] - '0') * mul[n - 1 - j]) {
          d[i][j + 1] = d[i][j] + (s[i + j] - '0') * mul[n - 1 - j];
          pre[i][j + 1] = 1;
        }
      }
    }
  ans.resize(2 * n);
  for (int i = n, j = n; i + j > 0;) {
    if (pre[i][j] == 0) {
      --i;
      ans[i + j] = 'M';
    } else {
      --j;
      ans[i + j] = 'H';
    }
  }
  cout << ans << endl;
  return 0;
}
