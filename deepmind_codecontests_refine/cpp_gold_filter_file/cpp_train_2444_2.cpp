#include <bits/stdc++.h>
char str[55][55];
int visit[55][55];
using namespace std;
int n, m;
int flag;
void dyna(char ch, int i, int j, char dir) {
  if (visit[i][j]) {
    flag = 1;
    return;
  }
  visit[i][j] = 1;
  if (dir != 'd' && i > 0 && str[i - 1][j] == ch && !flag)
    dyna(ch, i - 1, j, 'u');
  if (dir != 'u' && i < n - 1 && str[i + 1][j] == ch && !flag)
    dyna(ch, i + 1, j, 'd');
  if (dir != 'l' && j < m - 1 && str[i][j + 1] == ch && !flag)
    dyna(ch, i, j + 1, 'r');
  if (dir != 'r' && j > 0 && str[i][j - 1] == ch && !flag)
    dyna(ch, i, j - 1, 'l');
}
int main() {
  memset(visit, 0, sizeof(visit));
  flag = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!flag && visit[i][j] == 0) dyna(str[i][j], i, j, 'o');
  if (flag)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
