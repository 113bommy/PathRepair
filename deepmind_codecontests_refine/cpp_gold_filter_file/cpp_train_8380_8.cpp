#include <bits/stdc++.h>
using namespace std;
bool isvalid[100001];
string str;
int cnt = 0, n, m;
int len;
bool vis[501][501];
void dfs(int i, int j, int in) {
  if (in == len + 1) return;
  if (str[in] == 'U') {
    if (i == 1)
      dfs(i, j, in + 1);
    else {
      if (!vis[i - 1][j]) {
        vis[i - 1][j] = true;
        isvalid[in + 1] = true;
        cnt++;
      }
      dfs(i - 1, j, in + 1);
    }
  } else if (str[in] == 'D') {
    if (i == n)
      dfs(i, j, in + 1);
    else {
      if (!vis[i + 1][j]) {
        vis[i + 1][j] = true;
        isvalid[in + 1] = true;
        cnt++;
      }
      dfs(i + 1, j, in + 1);
    }
  } else if (str[in] == 'L') {
    if (j == 1)
      dfs(i, j, in + 1);
    else {
      if (!vis[i][j - 1]) {
        vis[i][j - 1] = true;
        isvalid[in + 1] = true;
        cnt++;
      }
      dfs(i, j - 1, in + 1);
    }
  } else if (str[in] == 'R') {
    if (j == m)
      dfs(i, j, in + 1);
    else {
      if (!vis[i][j + 1]) {
        vis[i][j + 1] = true;
        isvalid[in + 1] = true;
        cnt++;
      }
      dfs(i, j + 1, in + 1);
    }
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  isvalid[0] = true;
  vis[x][y] = true;
  cin >> str;
  len = str.length();
  dfs(x, y, 0);
  for (int i = 0; i <= len - 1; i++) {
    if (isvalid[i])
      cout << "1 ";
    else
      cout << "0 ";
  }
  if (isvalid[len])
    cout << (m * n - cnt);
  else
    cout << (m * n - cnt - 1);
  printf("\n");
  return 0;
}
