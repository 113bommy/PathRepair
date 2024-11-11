#include <bits/stdc++.h>
using namespace std;
int debug = 0;
const int N = 5005;
int n, m, lcs[N][N], ans[N][N], answer;
string a, b;
int main() {
  cin >> n >> m;
  cin >> a >> b;
  a = ' ' + a;
  b = ' ' + b;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      ans[i][j] = max(0, max(ans[i - 1][j], ans[i][j - 1]) - 1);
      for (int x = 0; x < 4; ++x)
        if (i - x > 0) {
          for (int y = 0; y < 4; ++y)
            if (j - y > 0) {
              if (a[i - x] == b[j - y]) {
                ans[i][j] =
                    max(ans[i][j], ans[i - x - 1][j - y - 1] + 2 - x - y + 1);
              }
            }
        }
      answer = max(answer, ans[i][j]);
    }
  }
  cout << answer << '\n';
}
