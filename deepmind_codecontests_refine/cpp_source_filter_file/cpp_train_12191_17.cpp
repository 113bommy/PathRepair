#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int pri[7] = {2, 3, 5, 7, 11, 13, 17};
int n, m, i, j, k, mp[1000005], mv[1000005], cntp, cntv, id[1000005];
int dis[305][305], ans[305][305];
vector<int> f[1000005];
void dfs(int x, int d, int a, int b, int lim1, int lim2) {
  if (!mp[a]) mp[a] = ++cntp;
  if (!mv[b]) mv[b] = ++cntv;
  if (dis[mp[a]][mv[b]] <= d) return;
  dis[mp[a]][mv[b]] = d;
  if (x == 7) return;
  int i, j;
  for (((i)) = (0); ((i)) <= (((int)(lim1 + 1)) - 1); ((i))++) {
    for (((j)) = (0); ((j)) <= (((int)(lim2 + 1)) - 1); ((j))++)
      if (d + abs(i - j) <= 10) {
        dfs(x + 1, d + abs(i - j), a, b * (j + 1), i, j);
      }
    a *= pri[x];
    if (a > 1000000) break;
  }
}
int main() {
  for (i = 2; i <= 1000000; i++)
    if (f[i].empty()) {
      for (j = i; j <= 1000000; j += i) {
        int t = j, c = 0;
        while (t % i == 0) {
          t /= i;
          c++;
        }
        f[j].push_back(c);
      }
    }
  for (((i)) = (1); ((i)) <= ((1000000)); ((i))++) {
    sort((f[i]).begin(), (f[i]).end(), greater<int>());
    id[i] = 1;
    for (((j)) = (0); ((j)) <= (((int)(f[i].size())) - 1); ((j))++)
      for (((k)) = (1); ((k)) <= ((f[i][j])); ((k))++) id[i] *= pri[j];
  }
  memset((dis), (0x16), (sizeof((dis))));
  dfs(0, 0, 1, 1, 20, 20);
  memset(ans, -1, sizeof(ans));
  read(n);
  while (n--) {
    int x, y;
    read(x);
    read(y);
    x = mp[id[x]];
    y = mp[id[y]];
    if (x > y) swap(x, y);
    if (ans[x][y] != -1) {
      printf("%d\n", ans[x][y]);
      continue;
    }
    ans[x][y] = 0x3bbbbbbb;
    for (((i)) = (1); ((i)) <= ((cntv)); ((i))++)
      ans[x][y] = min(ans[x][y], dis[x][i] + dis[y][i]);
    printf("%d\n", ans[x][y]);
  }
  return 0;
}
