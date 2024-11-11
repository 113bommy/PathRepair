#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
const int MAXN = 309;
int n, m;
struct Cell {
  queue<char> let;
  queue<char> wait;
  string res;
} ce[MAXN][MAXN];
char tmp[100009];
using tiiii = tuple<int, int, int, int>;
vector<tiiii> answ;
void AddMove(int r, int c, int tr, int tc) {
  char mc = ce[r][c].let.front();
  ce[r][c].let.pop();
  ce[tr][tc].let.push(mc);
  answ.emplace_back(r, c, tr, tc);
}
void Collect() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i == 1 && j == 1) || (i == n && j == m)) continue;
      while (ce[i][j].let.empty() == false) {
        char last = ce[i][j].let.front();
        if (last == '0') {
          if (j == 1)
            AddMove(i, j, 1, 1);
          else
            AddMove(i, j, i, 1);
        } else {
          if (j == m)
            AddMove(i, j, n, j);
          else
            AddMove(i, j, i, m);
        }
      }
    }
  }
}
void Distribute() {
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j < m; j++) {
      auto& res = ce[i][j].res;
      for (auto let : res) {
        if (let == '0') {
          if (i != 1) AddMove(1, 1, i, 1);
          AddMove(i, 1, i, j);
        } else {
          if (i != n) AddMove(n, m, i, m);
          AddMove(i, m, i, j);
        }
      }
    }
  }
  for (int i = 2; i < n; i++) {
    auto& res = ce[i][1].res;
    for (auto let : res) {
      if (let == '0') {
        AddMove(1, 1, i, 1);
      } else {
        AddMove(n, m, n, 1);
        AddMove(n, 1, i, 1);
      }
    }
  }
  for (int i = 2; i < n; i++) {
    auto& res = ce[i][m].res;
    for (auto let : res) {
      if (let == '0') {
        AddMove(1, 1, 1, m);
        AddMove(1, m, i, m);
      } else {
        AddMove(n, m, i, m);
      }
    }
  }
  int cnt1 = 0, cnt0 = 0;
  for (auto t : ce[1][1].res) {
    if (t == '0')
      cnt0++;
    else
      cnt1++;
  }
  for (auto t : ce[n][m].res) {
    if (t == '0')
      cnt0++;
    else
      cnt1++;
  }
  while (cnt0) {
    AddMove(1, 1, n, 1);
    cnt0--;
  }
  while (cnt1) {
    AddMove(n, m, 1, m);
    cnt1--;
  }
  for (auto t : ce[n][1].res) {
    if (t == '0')
      AddMove(1, 1, n, 1);
    else
      AddMove(n, m, n, 1);
  }
  for (auto t : ce[1][m].res) {
    if (t == '0')
      AddMove(1, 1, 1, m);
    else
      AddMove(n, m, 1, m);
  }
  for (auto t : ce[1][1].res) {
    if (t == '0')
      AddMove(n, 1, 1, 1);
    else
      AddMove(1, m, 1, 1);
  }
  for (auto t : ce[n][m].res) {
    if (t == '0')
      AddMove(n, 1, n, m);
    else
      AddMove(1, m, n, m);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%s", tmp);
      int len = strlen(tmp);
      for (int l = len - 1; l >= 0; l--) {
        ce[i][j].let.push(tmp[l]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%s", tmp);
      ce[i][j].res = tmp;
      reverse(ce[i][j].res.begin(), ce[i][j].res.end());
    }
  }
  while (ce[1][1].let.empty() == false) {
    AddMove(1, 1, n, 1);
  }
  while (ce[n][m].let.empty() == false) {
    AddMove(n, m, 1, m);
  }
  Collect();
  Collect();
  Distribute();
  printf("%d\n", (int)answ.size());
  for (auto t : answ) {
    int r, c, tr, tc;
    tie(r, c, tr, tc) = t;
    printf("%d %d %d %d\n", r, c, tr, tc);
  }
}
