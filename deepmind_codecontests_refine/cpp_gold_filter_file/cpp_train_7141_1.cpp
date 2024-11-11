#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  register int data = 0, w = 1;
  register char ch = 0;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar();
  return w * data;
}
const int MAX_N = 5e3 + 5;
const int MAX_M = 1e5 + 5;
int N, a[MAX_N], f[MAX_N][MAX_N], bln_nxt[MAX_M], bln_mod[10];
int ans = 0;
int main() {
  N = gi();
  for (int i = 1; i <= N; i++) a[i] = gi();
  for (int i = 0; i <= N; i++) {
    memset(bln_mod, 0, sizeof(bln_mod));
    memset(bln_nxt, 0, sizeof(bln_nxt));
    for (int j = 1; j < i; j++) {
      bln_nxt[a[j]] = max(bln_nxt[a[j]], f[i][j]);
      bln_mod[a[j] % 7] = max(bln_mod[a[j] % 7], f[i][j]);
    }
    for (int j = i + 1; j <= N; j++) {
      f[i][j] = max(bln_nxt[a[j] - 1], bln_nxt[a[j] + 1]) + 1;
      f[i][j] = max(f[i][j], f[i][0] + 1);
      f[i][j] = max(f[i][j], bln_mod[a[j] % 7] + 1);
      f[j][i] = f[i][j];
      bln_nxt[a[j]] = max(bln_nxt[a[j]], f[i][j]);
      bln_mod[a[j] % 7] = max(bln_mod[a[j] % 7], f[i][j]);
      ans = max(ans, f[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
