#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int s[N][210];
int a[N];
vector<int> num[210];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    for (int i = 0; i < 210; i++) num[i].clear();
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      num[a[i]].push_back(i);
      for (j = 1; j <= 26; j++) s[i][j] = s[i - 1][j];
      s[i][a[i]]++;
    }
    int l, r;
    int ans = 0;
    for (i = 1; i <= 200; i++) ans = max(ans, s[n][i]);
    for (i = 1; i <= 200; i++) {
      int cnt1 = 0;
      int si = (int)num[i].size();
      if (si == 1) continue;
      for (j = 0; j < si / 2; j++) {
        int l = num[i][j];
        int r = num[i][si - j - 1];
        cnt1 = (j + 1) * 2;
        for (int k = 1; k <= 200; k++) {
          ans = max(ans, cnt1 + s[r - 1][k] - s[l][k]);
        }
      }
    }
    cout << ans << endl;
  }
}
