#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, p[N], idx, vis[N], ty;
char s[N][N];
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) s[i][j] = '.';
  for (int i = (1); i <= (n); i++) scanf("%d", &p[i]);
  for (int i = (1); i <= (n); i++)
    if (!vis[i] && p[i] ^ i) {
      ty = 1;
      int j = i, ls = idx;
      for (vis[i] = 1; idx++, p[j] ^ i; vis[j = p[j]] = 1)
        if (j ^ 1) s[idx][j] = s[idx][p[j]] = j < p[j] ? '/' : '\\';
      s[idx][j] = s[idx][1] = '\\';
      if (i ^ 1) s[ls + 1][1] = '/';
    }
  cout << n - ty << endl;
  for (int i = (1); i <= (n); i++) puts(s[i] + 1);
  return 0;
}
