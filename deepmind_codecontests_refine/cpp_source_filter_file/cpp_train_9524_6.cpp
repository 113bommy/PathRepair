#include <bits/stdc++.h>
using namespace std;
int n;
string grid[50 + 10];
vector<pair<int, int> > oka, guti, trgt;
bool res[2 * 50 + 10][2 * 50 + 10];
bool valid(pair<int, int> nw) {
  if (nw.first < 1 || nw.first > n || nw.second < 1 || nw.second > n)
    return true;
  if (grid[nw.first][nw.second] == '.' || grid[nw.first][nw.second] == 'o')
    return false;
  return true;
}
int main() {
  int i, j, k, t, cs, m, mn, mx;
  pair<int, int> cur, nxt;
  bool cholbe = true;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> grid[i];
    grid[i] = "#" + grid[i];
    for (j = 1; j <= n; j++) {
      if (grid[i][j] == 'o')
        guti.push_back(make_pair(i, j));
      else if (grid[i][j] == 'x')
        trgt.push_back(make_pair(i, j));
    }
  }
  for (i = -n + 1; i <= n - 1; i++)
    for (j = -n + 1; j <= n - 1; j++) {
      for (k = 0; k < guti.size(); k++) {
        cur = guti[k];
        nxt = make_pair(cur.first + i, cur.second + j);
        if (!valid(nxt)) break;
      }
      if (k == guti.size()) oka.push_back(make_pair(i + n, j + n));
    }
  for (i = 0; i < oka.size(); i++) res[oka[i].first][oka[i].second] = true;
  for (i = 0; i < trgt.size(); i++) {
    bool ths = false;
    cur = trgt[i];
    for (j = 0; j < oka.size(); j++) {
      nxt = make_pair(cur.first - oka[j].first + n,
                      cur.second - oka[j].second + n);
      if (1 <= nxt.first && nxt.first <= n && 1 <= nxt.second &&
          nxt.second <= n && grid[nxt.first][nxt.second] == 'o')
        ths = true;
    }
    if (!ths) cholbe = false;
  }
  if (!cholbe) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (i = 1; i <= 2 * n - 1; i++) {
    for (j = 1; j <= 2 * n - 1; j++) {
      if (i == n && j == n)
        printf("o");
      else if (res[i][j])
        printf("x");
      else
        printf(".");
    }
    puts("");
  }
  return 0;
}
