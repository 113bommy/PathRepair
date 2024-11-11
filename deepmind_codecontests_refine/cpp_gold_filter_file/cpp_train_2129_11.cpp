#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double PI = atan(1.0) * 4;
const int inf = ~0U >> 1;
const int Dx[] = {1, 0, -1, 0}, Dy[] = {0, 1, 0, -1};
template <class T>
bool chmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
int sgn(T first) {
  return (first > eps) - (first < -eps);
}
char str[111][2];
map<char, int> has, has2;
bool vis[111], vis2[111];
bool check(const int &n) {
  for (int i = (0); i <= (int)(n - 1); i++)
    for (int j = (i + 1); j <= (int)(n - 1); j++) {
      bool u = 0, u1 = 0, u2 = 0;
      if (str[i][0] != str[j][0]) {
        if (vis[has[str[i][0]]] || vis[has[str[j][0]]]) u = 1;
      } else
        u1 = 1;
      if (str[i][1] != str[j][1]) {
        if (vis2[has2[str[i][1]]] || vis2[has2[str[j][1]]]) u = 1;
      } else
        u2 = 1;
      if (u1 && u2) continue;
      if (!u) return 0;
    }
  return 1;
}
int main() {
  int n, t1 = 0, t2 = 0;
  scanf("%d", &n);
  for (int i = (0); i <= (int)(n - 1); i++) {
    scanf("%s", str[i]);
    if (!has.count(str[i][0])) has[str[i][0]] = t1++;
    if (!has2.count(str[i][1])) has2[str[i][1]] = t2++;
  }
  int ans = t1 + t2;
  int N = 1 << (t1 + t2);
  for (int i = (0); i <= (int)(N - 1); i++) {
    memset(vis, 0, sizeof(vis));
    memset(vis2, 0, sizeof(vis2));
    for (int j = (0); j <= (int)(t1 - 1); j++)
      if (i & (1 << j)) vis[j] = 1;
    for (int j = (t1); j <= (int)(t1 + t2 - 1); j++)
      if (i & (1 << j)) vis2[j - t1] = 1;
    if (check(n)) chmin(ans, __builtin_popcount(i));
  }
  printf("%d\n", ans);
  return 0;
}
