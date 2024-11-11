#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
void readF() {}
char a[102][102];
int b[200002];
vector<pair<long long, long long> > ad[100002];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
string s, ss;
long long n, m, k, w;
long long ans, ans1;
long long mod = 1e9 + 7;
int dfn[55][55], LowLink[55][55];
set<pair<int, int> > st;
void tarjan(int nodex, int nodey, int parx, int pary) {
  LowLink[nodex][nodey] = dfn[nodex][nodey] = ++w;
  for (long long first = 0; first < 4; first++) {
    int chx = nodex + dx[first], chy = nodey + dy[first];
    if (chx < 0 || chx == n || chy < 0 || chy == m || a[chx][chy] == '.')
      continue;
    if (dfn[chx][chy] == -1) {
      tarjan(chx, chy, nodex, nodey);
      LowLink[nodex][nodey] = min(LowLink[nodex][nodey], LowLink[chx][chy]);
      if (LowLink[chx][chy] >= dfn[nodex][nodey]) {
        if (dfn[nodex][nodey] == 1 && k == 0)
          k = 1;
        else
          st.insert({nodex, nodey});
      }
    } else if (chx != parx || chy != pary)
      LowLink[nodex][nodey] = min(LowLink[nodex][nodey], dfn[chx][chy]);
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  readF();
  cin >> n >> m;
  int first = -1, second = -1;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        first = i, second = j;
        ans1++;
      }
    }
  if (ans1 <= 2) return cout << -1, 0;
  memset(dfn, -1, sizeof(dfn));
  ;
  tarjan(first, second, -1, -1);
  if (st.empty())
    ans = 2;
  else
    ans = 1;
  cout << ans;
  return 0;
}
