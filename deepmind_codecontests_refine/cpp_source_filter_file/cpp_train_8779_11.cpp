#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505, MAXC = 25;
vector<pair<int, pair<int, int> > > S[MAXN];
int n, m, a[MAXN][MAXC][2], par[MAXN][MAXC][MAXC], mp[MAXN][MAXN];
char tmp;
void pr(int f, int s, int r) {
  if (r != 0)
    pr(S[r - 1][par[r][f][s]].second.first,
       S[r - 1][par[r][f][s]].second.second, r - 1);
  for (int i = 0; i < m; i++)
    if (i % 2 == 0)
      cout << (char)(f + 'a');
    else
      cout << (char)(s + 'a');
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> tmp;
      mp[i][j] = tmp - 'a';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < MAXC; j++)
      for (int k = 0; k < 2; k++)
        for (int c = k; c < m; c += 2)
          if (mp[i][c] != j) a[i][j][k]++;
  for (int i = 0; i < MAXC; i++)
    for (int j = 0; j < MAXC; j++)
      if (i != j)
        S[0].push_back({a[0][i][0] + a[0][j][1], {i, j}}), par[0][i][j] = -1;
  sort(S[0].begin(), S[0].end());
  for (int r = 1; r < n; r++) {
    for (int i = 0; i < MAXC; i++)
      for (int j = 0; j < MAXC; j++)
        if (i != j)
          for (int c = 0; c < S[r - 1].size(); c++)
            if (S[r - 1][c].second.second != j &&
                S[r - 1][c].second.first != i) {
              S[r].push_back(
                  {S[r - 1][c].first + a[r][i][0] + a[r][j][1], {i, j}});
              par[r][i][j] = c;
              break;
            }
    sort(S[r].begin(), S[r].end());
  }
  cout << S[n - 1][0].first << endl;
  int f = S[n - 1][0].second.first, s = S[n - 1][0].second.second;
  pr(f, s, n - 1);
}
