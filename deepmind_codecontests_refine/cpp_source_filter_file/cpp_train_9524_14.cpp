#include <bits/stdc++.h>
using namespace std;
int n, cnt, cntx, ck[55][55];
char s[55][55], ans[400][400];
bool flag;
map<pair<int, int>, int> mp;
vector<pair<int, int> > v;
bool go(int dx, int dy) {
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].first + dx;
    int y = v[i].second + dy;
    if (x < 0 || x >= n || y < 0 || y >= n) continue;
    if (s[x][y] == '.') return false;
  }
  return true;
}
int main() {
  flag = true;
  cnt = cntx = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &s[i][j]);
      if (s[i][j] == 'o')
        v.push_back({i, j});
      else if (s[i][j] == 'x')
        cntx++;
    }
  }
  for (int i = -n; i <= n; i++) {
    for (int j = -n; j <= n; j++) {
      if (go(i, j)) {
        mp[{i, j}] = 1;
      }
    }
  }
  for (int k = 0; k < v.size(); k++) {
    for (auto it = mp.begin(); it != mp.end(); it++) {
      int x = v[k].first + (it->first).first;
      int y = v[k].second + (it->first).second;
      if (x < 0 || x >= n || y < 0 || y >= n) continue;
      if (!ck[x][y] && s[x][y] == 'x') {
        ck[x][y] = 1;
        cnt++;
      }
    }
  }
  if (cntx == cnt) {
    printf("YES\n");
    for (int i = 1; i <= (2 * n - 1); i++) {
      for (int j = 1; j <= (2 * n - 1); j++) {
        if (i == n && j == n)
          printf("o");
        else if (mp[{n - i, n - j}])
          printf("x");
        else
          printf(".");
      }
      printf("\n");
    }
  } else {
    printf("NO\n");
  }
}
