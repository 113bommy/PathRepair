#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int A[5010];
int X[5010], Y[5010], Z[5010];
int ans[5010][5010];
int p[5010], q[5010];
int cnt;
int n;
void check(int x) {
  for (int i = 0; i < n; i++) {
    int pos = A[i] ^ x;
    if (pos >= n) return;
    p[pos] = i;
    q[i] = pos;
  }
  if (p[0] != x) return;
  for (int i = 0; i < n; i++)
    if ((p[0] ^ q[i]) != A[i]) return;
  for (int i = 0; i < n; i++)
    if ((p[X[i]] ^ q[Y[i]]) != Z[i]) return;
  cnt++;
  for (int i = 0; i < n; i++) ans[cnt][i] = p[i];
  return;
}
int main() {
  srand(time(0));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("? 0 %d\n", i);
    fflush(stdout);
    scanf("%d", &A[i]);
    mp[make_pair(0, i)] = 1;
  }
  for (int i = 0; i < n; i++) {
    int x = i, y = (i + 1) % n;
    X[i] = x;
    Y[i] = y;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &Z[i]);
  }
  for (int i = 0; i < n; i++) check(i);
  printf("! %d\n", cnt);
  for (int j = 0; j < n; j++) printf("%d ", ans[1][j]);
  printf("\n");
  fflush(stdout);
  return 0;
}
