#include <bits/stdc++.h>
using namespace std;
int n;
int computer[201], check[3][201], vis[201];
vector<int> vv[201];
int bfs(int num, int st) {
  queue<int> q;
  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (check[num][i] == 0) q.push(i);
  }
  while (!q.empty()) {
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
      int head = q.front();
      q.pop();
      if (vis[head] == n) {
        q.push(head);
        break;
      }
      vis[head]++;
      if (computer[head] != st) {
        q.push(head);
        break;
      }
      for (int i = 0; i < vv[head].size(); i++) {
        check[num][vv[head][i]]--;
        if (check[num][vv[head][i]] == 0) q.push(vv[head][i]);
      }
    }
    st = (st == 3 ? 1 : st + 1);
    if (!q.empty()) ans++;
  }
  return ans;
}
int main() {
  while (cin >> n) {
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= n; i++) vv[i].clear();
    for (int i = 1; i <= n; i++) cin >> computer[i];
    for (int i = 1; i <= n; i++) {
      int ki;
      cin >> ki;
      for (int j = 1; j <= ki; j++) {
        int aj;
        cin >> aj;
        vv[aj].push_back(i);
        check[0][i]++, check[1][i]++, check[2][i]++;
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 3; i++) ans = min(ans, bfs(i - 1, i));
    cout << ans << endl;
  }
  return 0;
}
