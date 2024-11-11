#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int n, m;
bool a[maxn][maxn];
bool blx = 0, bly = 0;
int main() {
  cin >> n >> m;
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      if (s[j - 1] == '#')
        a[l][j] = 1;
      else
        a[l][j] = 0;
    }
  }
  for (int l = 1; l <= n; l++) {
    bool c = 0;
    int cnt = 0;
    for (int j = 1; j <= m + 1; j++) {
      if (a[l][j] != c) c = a[l][j], cnt++;
    }
    if (cnt >= 4) {
      cout << "-1" << endl;
      return 0;
    }
    if (cnt == 2) {
      ans++;
    }
    if (cnt == 0) {
      blx = 1;
    }
  }
  for (int j = 1; j <= m; j++) {
    bool c = 0;
    int cnt = 0;
    for (int l = 1; l <= n + 1; l++) {
      if (a[l][j] != c) c = a[l][j], cnt++;
    }
    if (cnt >= 4) {
      cout << "-1" << endl;
      return 0;
    }
    if (cnt == 0) {
      bly = 1;
    }
  }
  if (blx ^ bly == 1) {
    cout << -1 << endl;
    return 0;
  }
  for (int l = 1; l < n; l++) {
    for (int j = 1; j <= m; j++) {
      if (a[l][j] == 1 && a[l + 1][j] == 1) {
        ans--;
        break;
      }
    }
  }
  cout << ans << endl;
}
