#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
int v[2][N];
int len[2];
int main() {
  int n;
  scanf("%d", &n);
  v[1][0] = 0, v[1][1] = 1;
  v[0][0] = 1;
  len[1] = 1, len[0] = 0;
  int op = 1;
  for (int i = 2; i <= n; ++i) {
    op = 1;
    len[i & 1] = len[(i - 1) & 1] + 1;
    for (int j = 1; j <= len[i & 1]; ++j)
      if (v[(i - 1) & 1][j - 1] + v[i & 1][j] >= 2 ||
          v[(i - 1) & 1][j - 1] + v[i & 1][j] <= -2)
        op = 0;
    for (int j = 1; j <= len[i & 1]; ++j) {
      if (op)
        v[i & 1][j] += v[(i - 1) & 1][j - 1];
      else
        v[i & 1][j] -= v[(i - 1) & 1][j - 1];
    }
  }
  int now = n & 1;
  printf("%d\n", len[now]);
  if (v[now][len[now]] == -1) {
    for (int i = 0; i <= len[now]; ++i) v[now][i] -= v[now][i];
  }
  for (int i = 0; i <= len[now]; ++i)
    printf("%d%c", v[now][i], " \n"[i == len[now]]);
  now ^= 1;
  printf("%d\n", len[now]);
  if (v[now][len[now]] == -1) {
    for (int i = 0; i <= len[now]; ++i) v[now][i] -= v[now][i];
  }
  for (int i = 0; i <= len[now]; ++i)
    printf("%d%c", v[now][i], " \n"[i == len[now]]);
  return 0;
}
