#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int maxn = 3e5 + 10;
const int maxm = 1e6 + 10;
const long long mod = 998244353;
string s[maxn], f = "AGCT", temp[maxn];
string now[maxn], ans[maxn];
int a[4] = {0, 1, 2, 3};
int main() {
  int mn = 1e9;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  do {
    for (int i = 0; i < n; i++) now[i] = "";
    for (int i = 0; i < 4; i++) now[i / 2] += f[a[i]];
    for (int i = 2; i <= m; i++)
      now[0] += now[0][i - 2], now[1] += now[1][i - 2];
    for (int i = 2; i <= n; i++) now[i] = now[i - 2];
    for (int i = 0; i <= n; i++) temp[i] = now[i];
    int sum = 0;
    for (int j = 2; j < m; j++) {
      int now1 = 0, now2 = 0;
      for (int i = 0; i < n; i += 2) {
        now1 += (s[i][j] != now[i][j]) + (s[i + 1][j] != now[i + 1][j]);
        now2 += (s[i + 1][j] != now[i][j]) + (s[i][j] != now[i + 1][j]);
      }
      if (n & 1 && s[n][j] != now[n][j]) now1--;
      if (n & 1 && s[n][j] != now[n - 1][j]) now2--;
      if (now2 < now1) {
        for (int i = 0; i < n; i += 2) swap(now[i][j], now[i + 1][j]);
      }
      sum += min(now1, now2);
    }
    for (int j = 0; j < 2; j++)
      for (int i = 0; i < n; i++) sum += (s[i][j] != now[i][j]);
    if (sum < mn) {
      mn = sum;
      for (int i = 0; i < n; i++) ans[i] = now[i];
    }
    for (int i = 0; i <= n; i++) now[i] = temp[i];
    sum = 0;
    for (int i = 2; i < n; i++) {
      int now1 = 0, now2 = 0;
      for (int j = 0; j < m; j += 2) {
        now1 += (s[i][j] != now[i][j]) + (s[i][j + 1] != now[i][j + 1]);
        now2 += (s[i][j + 1] != now[i][j]) + (s[i][j] != now[i][j + 1]);
      }
      if (m & 1 && s[i][m] != now[i][m]) now1--;
      if (m & 1 && s[i][m] != now[i][m - 1]) now2--;
      if (now2 < now1) {
        for (int j = 0; j < m; j += 2) swap(now[i][j], now[i + 1][j]);
      }
      sum += min(now1, now2);
    }
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < m; j++) sum += (s[i][j] != now[i][j]);
    if (sum < mn) {
      mn = sum;
      for (int i = 0; i < n; i++) ans[i] = now[i];
    }
  } while (next_permutation(a, a + 4));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
