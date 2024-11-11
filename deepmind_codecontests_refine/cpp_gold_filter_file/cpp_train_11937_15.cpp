#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, k;
char mp[5][105][105];
int omin[5];
int emin[5];
void check(int c) {
  int odd1 = 0, odd0 = 0;
  int even1 = 0, even0 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2) {
        if (mp[c][i][j] == '1')
          odd1++;
        else
          odd0++;
      } else {
        if (mp[c][i][j] == '1')
          even1++;
        else
          even0++;
      }
    }
  }
  int t = (n * n) / 2 + 1;
  int l = (n * n) / 2;
  omin[c] = abs(even1 - t) + abs(odd0 - l);
  emin[c] = abs(even0 - t) + abs(odd1 - l);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        cin >> mp[i][j][k];
      }
    }
    check(i);
  }
  int ans = inf;
  ans = min(ans, omin[1] + omin[2] + emin[3] + emin[4]);
  ans = min(ans, omin[1] + omin[3] + emin[2] + emin[4]);
  ans = min(ans, omin[1] + omin[4] + emin[3] + emin[2]);
  ans = min(ans, omin[3] + omin[2] + emin[1] + emin[4]);
  ans = min(ans, omin[4] + omin[2] + emin[3] + emin[1]);
  ans = min(ans, omin[3] + omin[4] + emin[1] + emin[2]);
  cout << ans << endl;
  return 0;
}
