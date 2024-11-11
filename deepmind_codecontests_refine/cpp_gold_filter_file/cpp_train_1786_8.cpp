#include <bits/stdc++.h>
using namespace std;
int cnt[100010];
int q[100010];
bool have[100010][3];
int main() {
  int n, m;
  cin >> n >> m;
  {
    for (int i = 0; i <= n + 1; i++) {
      cnt[i] = 0;
      have[i][0] = have[i][1] = have[i][2] = false;
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", q + i);
      cnt[q[i]]++;
    }
    int ans = 3 * n - 2;
    int k;
    for (int i = 1; i <= m; i++) {
      k = q[i];
      if (!have[k][1]) {
        ans--;
        have[k][1] = true;
      }
      if ((cnt[k - 1] > 0) && (!have[k][0])) {
        ans--;
        have[k][0] = true;
      }
      if ((cnt[k + 1] > 0) && (!have[k][2])) {
        ans--;
        have[k][2] = true;
      }
      cnt[k]--;
    }
    printf("%d\n", ans);
  }
}
