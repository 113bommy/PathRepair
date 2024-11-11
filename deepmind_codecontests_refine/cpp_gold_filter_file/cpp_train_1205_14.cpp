#include <bits/stdc++.h>
using namespace std;
int n, m;
bool rev;
char t[52][52];
pair<int, int> ans[2][100010];
int cnt[2];
char revchange(char ch) {
  if (ch == 'U')
    return 'L';
  else if (ch == 'D')
    return 'R';
  else if (ch == 'L')
    return 'U';
  else
    return 'D';
}
void work(int i, int j, int id) {
  if (t[i][j] == 'L') return;
  if (t[i][j + 1] == 'L') {
    work(i + 1, j + 1, id);
    ans[id][cnt[id]++] = make_pair(i + 1, j + 2);
    t[i][j + 1] = 'U';
    t[i][j + 2] = 'U';
    t[i + 1][j + 1] = 'D';
    t[i + 1][j + 2] = 'D';
  }
  ans[id][cnt[id]++] = make_pair(i + 1, j + 1);
  t[i][j] = 'L';
  t[i][j + 1] = 'R';
  t[i + 1][j] = 'L';
  t[i + 1][j + 1] = 'R';
}
int main() {
  int i, j;
  scanf("%d %d\n", &n, &m);
  if (m & 1) rev = 1, swap(n, m);
  if (!rev)
    for (i = 0; i < n; i++, getchar())
      for (j = 0; j < m; j++) t[i][j] = getchar();
  else
    for (i = 0; i < m; i++, getchar())
      for (j = 0; j < n; j++) t[j][i] = revchange(getchar());
  for (i = 0; i < n; i++)
    for (j = 0; j < m / 2; j++)
      if (t[i][2 * j] != 'L') work(i, 2 * j, 0);
  if (!rev)
    for (i = 0; i < n; i++, getchar())
      for (j = 0; j < m; j++) t[i][j] = getchar();
  else
    for (i = 0; i < m; i++, getchar())
      for (j = 0; j < n; j++) t[j][i] = revchange(getchar());
  for (i = 0; i < n; i++)
    for (j = 0; j < m / 2; j++)
      if (t[i][2 * j] != 'L') work(i, 2 * j, 1);
  printf("%d\n", cnt[0] + cnt[1]);
  for (i = 0; i < cnt[0]; i++)
    if (!rev)
      printf("%d %d\n", ans[0][i].first, ans[0][i].second);
    else
      printf("%d %d\n", ans[0][i].second, ans[0][i].first);
  for (i = cnt[1] - 1; i >= 0; i--)
    if (!rev)
      printf("%d %d\n", ans[1][i].first, ans[1][i].second);
    else
      printf("%d %d\n", ans[1][i].second, ans[1][i].first);
}
