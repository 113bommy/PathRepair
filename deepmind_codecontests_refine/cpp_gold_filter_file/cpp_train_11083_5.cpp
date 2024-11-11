#include <bits/stdc++.h>
using namespace std;
int N, M;
int lt[100005], rt[100005], q[100005];
int a[100005], lg[100005];
int s[100005][31];
int Ask(int x, int y) {
  int tmp = lg[y - x + 1];
  return s[x][tmp] & s[y - (1 << tmp) + 1][tmp];
}
void End(int x) {
  printf("%s\n", x ? "YES" : "NO");
  if (x)
    for (int i = 1; i <= N; i++) printf("%d ", a[i]);
  exit(0);
}
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for (i = 1; i <= M; i++) {
    scanf("%d %d %d", &lt[i], &rt[i], &q[i]);
    for (j = 0; j < 30; j++)
      if ((q[i] >> j) & 1) s[lt[i]][j]++, s[rt[i] + 1][j]--;
  }
  for (i = 1; i <= N; i++)
    for (j = 0; j < 30; j++) {
      s[i][j] += s[i - 1][j];
      if (s[i][j]) a[i] += (1 << j);
    }
  for (i = 1; i <= N; i++) lg[i] = lg[i - 1] + (i - 1 == (1 << lg[i - 1] + 1));
  for (i = 1; i <= N; i++) s[i][0] = a[i];
  for (j = 1; (1 << j) <= N; j++)
    for (i = 1; i + (1 << j - 1) <= N; i++)
      s[i][j] = (s[i][j - 1] & s[i + (1 << j - 1)][j - 1]);
  for (i = 1; i <= M; i++)
    if (Ask(lt[i], rt[i]) != q[i]) End(0);
  End(1);
  return 0;
}
