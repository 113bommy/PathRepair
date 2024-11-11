#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
char s[maxn];
int mark[33];
int vis[maxn][27];
int ok[maxn];
vector<int> v[27];
void solve() {
  cin >> s;
  int len = strlen(s);
  memset(mark, 1, sizeof(mark));
  for (int i = 0; i < len; i++) {
    v[s[i] - 'a'].push_back(i);
  }
  double up = 0;
  for (int k = 0; k < 26; k++) {
    if (v[k].size() == 0) continue;
    memset(vis, 0, sizeof(vis));
    memset(ok, 1, sizeof(ok));
    int tcnt = len - 1;
    for (int i = 0; i < v[k].size() && tcnt; i++) {
      for (int j = (v[k][i] + 1) % len, cnt = 1; cnt < len && tcnt;
           cnt++, j = (j + 1) % len) {
        if (vis[cnt][s[j] - 'a'] == -1)
          continue;
        else if (vis[cnt][s[j] - 'a'])
          vis[cnt][s[j] - 'a'] = -1;
        else
          vis[cnt][s[j] - 'a'] = 1;
      }
    }
    int maxx = 0;
    for (int i = 0, temp; i < len; i++) {
      temp = 0;
      for (int j = 0; j < 26; j++)
        if (vis[i][j] == 1) temp++;
      maxx = max(temp, maxx);
    }
    up += maxx;
  }
  printf("%.10lf\n", up / len);
}
int main() {
  solve();
  int MARKEOF;
  if (scanf("%d", &MARKEOF))
    ;
  return 0;
}
