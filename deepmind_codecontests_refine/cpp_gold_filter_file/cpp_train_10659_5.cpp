#include <bits/stdc++.h>
using namespace std;
const int MAX = 1900;
int nxt[MAX];
vector<int> v, num, ans;
int c[MAX], cnt[MAX], len[MAX];
bool mark[MAX];
int n, m;
bool dp[MAX][MAX];
void DFS(int x, int color) {
  c[x] = color;
  cnt[color]++;
  if (nxt[x] != 0) {
    len[nxt[x]] = len[x] + 1;
    DFS(nxt[x], color);
  }
}
int main() {
  cin >> n >> m;
  int k, color = 1;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    if (k != 0) {
      nxt[k] = i;
    } else {
      mark[i] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mark[i] == 1) {
      len[i] = 1;
      DFS(i, color);
      color++;
    }
  }
  for (int i = 1; i <= color - 1; i++) {
    if (i != c[m]) {
      num.push_back(cnt[i]);
    }
  }
  if (num.size() != 0) {
    dp[0][num[0]] = 1;
    for (int i = 1; i < num.size(); i++) {
      for (int j = 0; j < 1000; j++) {
        if (dp[i - 1][j] == 1) dp[i][j] = dp[i][j + num[i]] = 1;
      }
      dp[i][num[i]] = 1;
    }
    for (int i = 0; i < 1000; i++) {
      if (i + len[m] == len[m]) continue;
      if (dp[num.size() - 1][i] == 1) ans.push_back(i + len[m]);
    }
  }
  ans.push_back(len[m]);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
