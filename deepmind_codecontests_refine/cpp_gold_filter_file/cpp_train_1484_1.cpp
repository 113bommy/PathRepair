#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
int vis[200010], pr[200010], cnt = 0;
vector<int> val[200010];
void getpr(int lim = 200000) {
  for (int i = 2; i <= lim; i++)
    if (!vis[i]) {
      vis[i] = ++cnt;
      pr[cnt] = i;
      for (int j = 2; j * i <= lim; j++) vis[j * i] = true;
    }
}
int main() {
  ios::sync_with_stdio(false);
  getpr();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= cnt && pr[j] * pr[j] <= x; j++) {
      int tmp = 0;
      while (x % pr[j] == 0) x /= pr[j], tmp++;
      if (tmp) val[j].push_back(tmp);
    }
    if (x > 1) val[vis[x]].push_back(1);
  }
  long long ans = 1;
  for (int i = 1; i <= cnt; i++) {
    sort(val[i].begin(), val[i].end());
    int t;
    if (n - val[i].size() >= 2)
      continue;
    else if (n - val[i].size() == 1)
      t = val[i][0];
    else
      t = val[i][1];
    for (int j = 1; j <= t; j++) ans *= pr[i];
  }
  cout << ans << endl;
  return 0;
}
