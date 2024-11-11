#include <bits/stdc++.h>
using namespace std;
char mp[55][55];
int dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
char s[105];
int op[4] = {0, 1, 2, 3};
int ha[4];
struct Node {
  int x, y;
} st, u, v;
bool ok() {
  for (int i = 0; i < 4; i++) ha[op[i]] = i;
  u = st;
  for (int i = 0; i < strlen(s); i++) {
    int k = ha[s[i] - '0'];
    v.x = u.x + dir[k][0];
    v.y = u.y + dir[k][1];
    if (v.x < 0 || v.x > n || v.y < 0 || v.y > m || mp[v.x][v.y] == '#')
      return false;
    if (mp[v.x][v.y] == 'E') return true;
    u = v;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 'S') {
        st.x = i;
        st.y = j;
      }
    }
  }
  scanf("%s", s);
  int ans = 0;
  do {
    if (ok()) ans++;
  } while (next_permutation(op, op + 4));
  printf("%d\n", ans);
}
