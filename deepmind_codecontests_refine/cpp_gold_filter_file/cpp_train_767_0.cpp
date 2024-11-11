#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int maxn = 3010;
const int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int Map[maxn][maxn * 2];
int x, y, N, M, K, pa[maxn * maxn * 2], vis[maxn * maxn * 2];
int findpa(int x) {
  if (x == 0) return 0;
  if (x == pa[x])
    return x;
  else
    return pa[x] = findpa(pa[x]);
}
int v = 0;
char ch;
int get() {
  while (!isdigit(ch = getchar()))
    ;
  v = ch - '0';
  while (isdigit(ch = getchar())) v = v * 10 + ch - '0';
  return v;
}
int main() {
  int ans = 0;
  cin >> N >> M >> K;
  int MM = M * 2;
  if (M == 1) return puts("0"), 0;
  for (int i = 1; i <= K; i++) {
    x = get();
    y = get();
    y--;
    if (Map[x][y]) continue;
    int bo = 1;
    for (int k = 0; k < 8; k++)
      if (Map[x + dx[k]][(y + dy[k] + M) % MM]) {
        int z = findpa((x + dx[k] - 1) * (MM) + (y + dy[k] + M) % MM);
        if (z != 0) vis[z] = i;
      }
    for (int k = 0; k < 8; k++)
      if (Map[x + dx[k]][(y + dy[k] + MM) % MM])
        if (vis[findpa((x + dx[k] - 1) * (MM) + (y + dy[k] + MM) % MM)] == i)
          bo = 0;
    if (bo) {
      pa[(x - 1) * (MM) + y] = (x - 1) * (MM) + y;
      for (int k = 0; k < 8; k++)
        if (Map[x - dx[k]][(y - dy[k] + MM) % MM]) {
          int t = findpa((x - dx[k] - 1) * (MM) + (y - dy[k] + MM) % MM);
          pa[t] = (x - 1) * (MM) + y;
        }
      Map[x][y] = 1;
      y += M;
      pa[(x - 1) * (MM) + y] = (x - 1) * (MM) + y;
      for (int k = 0; k < 8; k++)
        if (Map[x - dx[k]][(y - dy[k] + MM) % MM]) {
          int t = findpa((x - dx[k] - 1) * (MM) + (y - dy[k] + MM) % MM);
          pa[t] = (x - 1) * (MM) + y;
        }
      Map[x][y] = 1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
