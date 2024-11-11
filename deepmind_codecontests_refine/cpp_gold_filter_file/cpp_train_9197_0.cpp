#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 11, mod = 1e9 + 7;
int ans1, ans[1][52], n, m, k, a[2][52][52], ans5[2][52][52];
bool l1, l2;
string s;
void ww() {
  int ansd;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      ansd = 0;
      for (int r = 0; r < m; r++) {
        ansd = (ansd + (ans5[l1][i][r] * a[l2][r][j]) % mod) % mod;
      }
      ans5[1 - l1][i][j] = ansd;
    }
  }
  l1 = 1 - l1;
}
void ww1() {
  int ansd;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      ansd = 0;
      for (int r = 0; r < m; r++) {
        ansd = (ansd + (a[l2][i][r] * a[l2][r][j]) % mod) % mod;
      }
      a[1 - l2][i][j] = ansd;
    }
  }
  l2 = 1 - l2;
}
void p(int b) {
  while (b) {
    if (b % 2 == 1) {
      ww();
    }
    ww1();
    b /= 2;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      a[0][i][j] = 1;
      if (i == j) ans5[0][i][j] = 1;
    }
  }
  for (int i = 0; i < m; i++) ans[0][i] = 1;
  for (int i = 0; i < k; i++) {
    cin >> s;
    int a1, a2;
    if (s[0] > 90)
      a1 = s[0] - 97;
    else
      a1 = s[0] - 65 + 26;
    if (s[1] > 90)
      a2 = s[1] - 97;
    else
      a2 = s[1] - 65 + 26;
    a[0][a2][a1] = 0;
  }
  p(n - 1);
  int ansy;
  for (int i = 0; i < m; i++) {
    for (int r = 0; r < m; r++) {
      ans1 = (ans1 + (ans5[l1][i][r] * ans[0][r]) % mod) % mod;
    }
  }
  cout << ans1;
  return 0;
}
