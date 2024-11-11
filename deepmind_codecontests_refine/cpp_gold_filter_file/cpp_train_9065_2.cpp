#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
set<int> E[maxn];
int vis[maxn][maxn];
int a[maxn];
int dp[maxn][maxn];
string s;
vector<pair<int, int> > mono, multi;
stack<pair<int, int> > S;
vector<pair<int, int> > V;
int n, m;
int cnt[55];
char mmp[maxn][maxn];
struct node {
  int x, y, l;
};
int expand(int r, int c) {
  int l = 1;
  while (r + l <= n && r - l >= 1 && c + l <= m && c - l >= 1 &&
         mmp[r + l][c] == '*' && mmp[r][c - l] == '*' && mmp[r][c + l] == '*' &&
         mmp[r - l][c] == '*') {
    vis[r][c] = vis[r + l][c] = vis[r - l][c] = vis[r][c + l] = vis[r][c - l] =
        1;
    l++;
  }
  return (l - 1);
}
int main() {
  cin >> n >> m;
  for (int i = (int)1; i <= (int)n; i++) scanf("%s", mmp[i] + 1);
  int cnt = 0;
  vector<node> Ans;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)1; j <= (int)m; j++)
      if (mmp[i][j] == '*') {
        cnt++;
        int x = expand(i, j);
        if (x) Ans.push_back({i, j, x});
      }
  int ccnt = 0;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)1; j <= (int)m; j++) {
      ccnt += vis[i][j];
    }
  if (ccnt != cnt)
    puts("-1");
  else {
    cout << Ans.size() << endl;
    for (auto t : Ans) {
      printf("%d %d %d\n", t.x, t.y, t.l);
    }
  }
  cin >> n;
}
