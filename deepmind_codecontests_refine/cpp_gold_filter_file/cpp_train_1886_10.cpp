#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
inline int lowbit(int x) { return x & -x; }
const int N = 1e5 + 10;
const int mod = (int)1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = (1LL << 62);
const double PI = acos(-1.0);
using namespace std;
int n;
char p[3005], q[3005];
int nex[3005];
string from[3005], to[3005];
int b[3005], e[3005];
bool vis[3005];
void get_nex() {
  int i, j;
  int len = strlen(p);
  j = nex[0] = -1;
  i = 0;
  for (; i < len;) {
    for (; j != -1 && p[i] != p[j];) j = nex[j];
    nex[++i] = ++j;
  }
}
bool KMP(int x, int L) {
  int i, j;
  int len = from[x].length();
  i = j = 0;
  for (; i < len;) {
    for (; j != -1 && from[x][i] != p[j];) j = nex[j];
    j++;
    if (j == L) {
      if (!vis[x]) return false;
      if (e[x] != i) {
        return false;
      }
      return true;
    }
    i++;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", p);
    from[i] = p;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", q);
    to[i] = q;
  }
  int L = 0;
  for (int i = 1; i <= n; i++) {
    int be = -1, en = -1;
    for (int j = 0; j < from[i].length(); j++)
      if (from[i][j] != to[i][j]) {
        if (be == -1) be = j;
        en = j;
      }
    if (be == -1) continue;
    vis[i] = true;
    b[i] = be;
    e[i] = en;
    if (!L) {
      for (int j = be; j <= en; j++) {
        p[L] = from[i][j];
        q[L++] = to[i][j];
      }
      p[L] = 0;
      q[L] = 0;
    } else {
      if (en - be + 1 != L) {
        printf("NO\n");
        return 0;
      } else {
        for (int j = be; j <= en; j++) {
          if (from[i][j] != p[j - be] || to[i][j] != q[j - be]) {
            printf("NO\n");
            return 0;
          }
        }
      }
    }
  }
  for (;;) {
    char ch = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) continue;
      if (b[i] == 0) {
        flag = true;
        break;
      }
      if (!ch) ch = from[i][b[i] - 1];
      if (ch != from[i][b[i] - 1]) {
        flag = true;
        break;
      }
    }
    if (flag) break;
    for (int i = 1; i <= n; i++) b[i]--;
  }
  for (;;) {
    char ch = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) continue;
      if (e[i] == from[i].length() - 1) {
        flag = true;
        break;
      }
      if (!ch) ch = from[i][e[i] + 1];
      if (ch != from[i][e[i] + 1]) {
        flag = true;
        break;
      }
    }
    if (flag) break;
    for (int i = 1; i <= n; i++) e[i]++;
  }
  for (int i = 1; i <= n; i++)
    if (vis[i]) {
      L = 0;
      for (int j = b[i]; j <= e[i]; j++) {
        p[L] = from[i][j];
        q[L++] = to[i][j];
      }
      p[L] = 0;
      q[L] = 0;
      break;
    }
  get_nex();
  for (int i = 1; i <= n; i++) {
    if (!KMP(i, L)) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  printf("%s\n%s\n", p, q);
  return 0;
}
