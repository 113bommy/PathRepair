#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int MAXLG = 22;
int val[1 << MAXLG];
int ans[MAX], A[MAX];
void insert(int u) {
  int msk = 0;
  for (int i = 0; i < (MAXLG); i++)
    if (!(u & (1 << i))) msk |= 1 << i;
  val[msk] = u;
}
int dfs(int msk) {
  if (val[msk] != -2) return val[msk];
  val[msk] = -1;
  int omsk = (1 << MAXLG) - 1;
  omsk ^= msk;
  for (; omsk && val[msk] == -1; omsk ^= ((omsk) & (-(omsk))))
    val[msk] = dfs(msk | ((omsk) & (-(omsk))));
  return val[msk];
}
int main() {
  fill(val, val + (1 << MAXLG), -2);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) {
    scanf("%d", A + i);
    insert(A[i]);
  }
  for (int i = 0; i < (1 << MAXLG); i++)
    if (val[i] == -2) dfs(i);
  for (int i = 0; i < (n); i++) {
    int msk = 0;
    for (int j = 0; j < (MAXLG); j++)
      if (A[i] & (1 << j)) msk |= 1 << j;
    printf("%d%c", val[msk], " \n"[i == n - 1]);
  }
  return 0;
}
