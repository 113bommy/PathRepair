#include <bits/stdc++.h>
int scan() {
  int noRead = 0;
  char p = getchar();
  for (; p < 33;) {
    p = getchar();
  }
  while (p > 32) {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p = getchar();
  }
  return noRead;
}
using namespace std;
int cnt[100001], a[100001], vis[100001], steps[100001];
int main(void) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  memset(steps, 0, sizeof(steps));
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    queue<pair<int, int> > q;
    q.push(make_pair(x, 0));
    while (!q.empty()) {
      x = q.front().first;
      int y = q.front().second;
      q.pop();
      if (x > 100001) continue;
      if (vis[x] == i) continue;
      vis[x] = i;
      steps[x] += y;
      cnt[x]++;
      q.push(make_pair(x / 2, y + 1));
      q.push(make_pair(x * 2, y + 1));
    }
  }
  int ans = 100001;
  for (int i = 0; i < 100001; ++i) {
    if (cnt[i] == n) ans = min(ans, steps[i]);
  }
  cout << ans;
  return 0;
}
