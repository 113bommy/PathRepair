#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const int maxn = 50 + 10;
const int base = 29;
const int mod = 1e9 + 7;
const int INF = 1e18;
int a[maxn], b[maxn], n, m;
int a2[maxn];
int grid[10][300];
bool mark[20][32][200000];
vector<int> vc[maxn];
inline void solve(int col, int colmask, int HashRow) {
  if (col == m) {
    for (int i = 0; i < n; i++)
      if (a2[i] < a[i]) return;
    for (int i = 0; i < n; i++, cout << "\n")
      for (int j = 0; j < m; j++) {
        if (grid[i][j])
          cout << "*";
        else
          cout << ".";
      }
    exit(0);
  }
  if (mark[col][colmask][HashRow]) return;
  mark[col][colmask][HashRow] = true;
  for (auto colmask2 : vc[b[col]]) {
    bool fl = true;
    for (int i = 0; i < n; i++) {
      if (colmask2 & (1 << i)) {
        grid[i][col] = true;
        if ((col == 0 || grid[i][col - 1] == 0)) {
          a2[i]++;
          if (a2[i] > a[i]) fl = false;
        }
      }
    }
    if (fl) {
      int newHashRow = 0;
      for (int i = 0; i < n; i++) newHashRow = newHashRow * n + a2[i];
      solve(col + 1, colmask2, newHashRow);
    }
    for (int i = 0; i < n; i++) {
      if (colmask2 & (1 << i)) {
        grid[i][col] = false;
        if ((col == 0 || grid[i][col - 1] == 0)) a2[i]--;
      }
    }
  }
}
int32_t main() {
  n = in(), m = in();
  for (int i = 0; i < n; i++) a[i] = in();
  for (int i = 0; i < m; i++) b[i] = in();
  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = 0, tmp = 0;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
        if (!tmp) tmp = 1, cnt++;
      } else
        tmp = 0;
    }
    vc[cnt].push_back(mask);
  }
  solve(0, 0, 0);
}
