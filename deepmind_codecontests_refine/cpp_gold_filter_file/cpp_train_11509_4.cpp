#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int b[N * N], ab[N][N];
int a[N][N], c[N][N], s[N][N], sz[N * N], cnt;
char ch[N];
int n, k, ans = 0, now_sz;
struct Data {
  int x, y;
  Data(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
queue<Data> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int t) {
  Data tmp;
  int x, y, xx, yy;
  sz[t] = 1;
  while (!Q.empty()) {
    tmp = Q.front(), Q.pop();
    x = tmp.x, y = tmp.y;
    for (int i = 0; i < 4; ++i) {
      xx = x + dx[i], yy = y + dy[i];
      if (xx > n || yy > n || xx < 1 || yy < 1 || a[xx][yy] || c[xx][yy])
        continue;
      sz[t]++, c[xx][yy] = t;
      Q.push(Data(xx, yy));
    }
  }
}
void add(int t) {
  if (t == 0) return;
  if (b[t] == 0) now_sz += sz[t];
  b[t]++;
}
void del(int t) {
  if (t == 0) return;
  if (b[t] == 1) now_sz -= sz[t];
  b[t]--;
}
int main() {
  scanf("%d %d", &n, &k);
  if (k >= n) {
    printf("%d\n", n * n);
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= n; ++j)
      a[i][j] = ch[j] == 'X',
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!a[i][j] && !c[i][j]) c[i][j] = ++cnt, Q.push(Data(i, j)), bfs(cnt);
  for (int i = 1; i + k - 1 <= n; ++i) {
    memset(b, 0, 4 * (cnt + 1)), now_sz = 0;
    for (int o1 = i - 1; o1 <= i + k; ++o1)
      if (o1 != i - 1 && o1 != i + k)
        for (int o2 = 1; o2 <= k + 1; ++o2) add(c[o1][o2]);
      else
        for (int o2 = 1; o2 <= k; ++o2) add(c[o1][o2]);
    ans = max(ans, now_sz + s[i + k - 1][k] - s[i - 1][k] - s[i + k - 1][0] +
                       s[i - 1][0]);
    for (int j = 2; j + k - 1 <= n; ++j) {
      for (int p = i; p <= i + k - 1; ++p) add(c[p][j + k]), del(c[p][j - 2]);
      del(c[i - 1][j - 1]), add(c[i - 1][j + k - 1]);
      del(c[i + k][j - 1]), add(c[i + k][j + k - 1]);
      ans = max(ans, now_sz + s[i + k - 1][j + k - 1] - s[i - 1][j + k - 1] -
                         s[i + k - 1][j - 1] + s[i - 1][j - 1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
