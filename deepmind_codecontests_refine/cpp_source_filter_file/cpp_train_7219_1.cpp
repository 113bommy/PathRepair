#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> q[2003];
int a[2003];
int d[2003];
int tmp[2003];
int solve(int cnt) {
  int ans = n;
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0 && a[i] == cnt) pos = i;
  }
  int res = 0;
  if (pos == 0) return 1000000;
  while (1) {
    while (1) {
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (d[i] == 0 && a[i] == cnt) {
          flag = 1;
          d[i] = -1;
          res++;
          for (int j = 0; j < q[i].size(); j++) {
            d[q[i][j]]--;
          }
        }
      }
      if (flag == 0) break;
    }
    if (res == n) break;
    cnt++;
    ans++;
    if (cnt == 4) cnt = 1;
  }
  return ans;
}
int main() {
  cin >> n;
  memset(d, 0, sizeof(d));
  int ans = 1000000;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int k, a;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> a;
      q[i].push_back(a);
      d[a]++;
    }
  }
  for (int i = 1; i <= n; i++) tmp[i] = d[i];
  ans = min(ans, solve(1));
  for (int i = 1; i <= n; i++) d[i] = tmp[i];
  ans = min(ans, solve(2));
  for (int i = 1; i <= n; i++) d[i] = tmp[i];
  ans = min(ans, solve(3));
  cout << ans << endl;
  return 0;
}
