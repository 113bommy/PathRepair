#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100 + 7;
const long long MOD = 1e9 + 7;
long long a[MAXN], b[MAXN], c[MAXN];
long long cge[3][100][MAXN];
int main() {
  int n, T, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) cge[1][0][i] = cge[2][0][i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cge[1][i][j] = cge[1][i - 1][a[j]];
      cge[2][i][a[j]] = cge[2][i - 1][j];
    }
  }
  int ans1 = -1, ans2 = -1;
  for (int i = 0; i <= m; i++) {
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      if (cge[1][i][j] == b[j]) {
        continue;
      } else {
        flag = 1;
        break;
      }
    }
    if (flag) {
      continue;
    } else {
      ans1 = i;
      break;
    }
  }
  for (int i = 0; i <= m; i++) {
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      if (cge[2][i][j] == b[j]) {
        continue;
      } else {
        flag = 1;
        break;
      }
    }
    if (flag) {
      continue;
    } else {
      ans2 = i;
      break;
    }
  }
  if (ans1 == 0) {
    if (m == 0)
      return puts("YES"), 0;
    else
      return puts("NO"), 0;
  }
  if (ans1 == 1) {
    if (m == 1)
      return puts("YES"), 0;
    else if (m % 2 && ans2 != 1)
      return printf("YES\n"), 0;
  }
  if (ans2 == 1) {
    if (m == 1)
      return puts("YES"), 0;
    else if (m % 2 && ans1 != 1)
      return printf("YES\n"), 0;
  }
  if (ans1 > 1 && (m - ans1) % 2 == 0) return puts("YES"), 0;
  if (ans2 > 1 && (m - ans2) % 2 == 0) return puts("YES"), 0;
  return puts("NO"), 0;
}
