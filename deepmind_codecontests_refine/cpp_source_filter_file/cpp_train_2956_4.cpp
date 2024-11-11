#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int song[N][2], kkk[N];
int ans[N];
int main() {
  int n, m;
  int i, j;
  while (cin >> n >> m) {
    for (i = 1; i <= n; i++) cin >> song[i][0] >> song[i][1];
    int nowt = 0;
    for (i = 1; i <= m; i++) cin >> kkk[i];
    int index = 1;
    for (i = 1; i <= n; i++) {
      nowt += song[i][0] * song[i][1];
      for (j = index;; j++) {
        if (j > m) break;
        if (kkk[j] <= nowt) {
          ans[j] = i;
        } else {
          index = j - 1;
          break;
        }
      }
      if (nowt >= kkk[m]) break;
    }
    for (i = 1; i <= m; i++) cout << ans[i] << endl;
  }
  return 0;
}
