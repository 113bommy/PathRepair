#include <bits/stdc++.h>
using namespace std;
int cnt[105];
int a[400500];
int sum[400500];
int mp[400500];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  int mx = -1;
  int flag = 1;
  int dex = 0;
  int x = min(n, 100);
  for (int i = 1; i <= x; i++) {
    if (cnt[i] == mx) {
      flag++;
    } else if (cnt[i] > mx) {
      dex = i;
      mx = cnt[i];
      flag = 1;
    }
  }
  if (flag > 1) {
    cout << n << endl;
  } else {
    int ans = 0;
    int dir = 2e5;
    for (int i = 1; i <= x; i++) {
      memset(mp, 0, sizeof(mp));
      if (i == dex) continue;
      for (int j = 1; j <= n; j++) {
        sum[j] = sum[j - 1];
        if (a[j] == dex) sum[j]++;
        if (a[j] == i) sum[j]--;
        if (!mp[sum[j] + dir] && sum[j] + dir != 0)
          mp[sum[j] + dir] = j;
        else
          ans = max(ans, j - mp[sum[j] + dir]);
      }
    }
    cout << ans << endl;
  }
}
