#include <bits/stdc++.h>
using namespace std;
int n, m;
char inp[260][260];
bool cov[260][260];
int mx, my, Mx, My;
vector<int> outai;
vector<int> outaj;
void dfs(int i, int j) {
  cov[i][j] = true;
  mx = min(mx, j);
  my = min(i, my);
  Mx = max(Mx, j);
  My = max(My, i);
  outai.push_back(i);
  outaj.push_back(j);
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int y = i + dy;
      int x = j + dx;
      if (y < 0 || y >= n || x < 0 || x >= m || inp[y][x] == '0' || cov[y][x])
        continue;
      dfs(y, x);
    }
  }
}
int ar[4];
bool chk[4][860];
bool firstType() {
  if (My - my + 1 <= 1 || My - my + 1 != Mx - mx + 1) return false;
  memset(chk, 0, sizeof(chk));
  for (int t = 0; t < outai.size(); t++) {
    bool ch = false;
    if (outai[t] == my && outaj[t] >= mx && outaj[t] <= Mx)
      chk[0][outaj[t]] = true, ch = true;
    if (outai[t] >= my && outai[t] <= My && outaj[t] == mx)
      chk[2][outai[t]] = true, ch = true;
    if (outai[t] == My && outaj[t] >= mx && outaj[t] <= Mx)
      chk[1][outaj[t]] = true, ch = true;
    if (outai[t] >= my && outai[t] <= My && outaj[t] == Mx)
      chk[3][outai[t]] = true, ch = true;
    if (!ch) return false;
  }
  for (int x = mx; x <= Mx; x++)
    if (!chk[0][x] || !chk[1][x]) return false;
  for (int y = my; y <= My; y++)
    if (!chk[2][y] || !chk[3][y]) return false;
  return true;
}
int getcord(int i, int j) {
  int d = min(i, j);
  return d * 2 + (i - d) + (j - d);
}
bool secondType() {
  memset(ar, 0, sizeof(ar));
  mx = my = 260;
  Mx = My = -1;
  for (int t = 0; t < outai.size(); t++) {
    int ty = outai[t];
    int tx = outaj[t];
    outai[t] = getcord(ty, tx);
    outaj[t] = getcord(ty, m - 1 - tx);
    mx = min(outaj[t], mx);
    Mx = max(outaj[t], Mx);
    My = max(outai[t], My);
    my = min(outai[t], my);
  }
  for (int t = 0; t < outai.size(); t++) {
    if ((outai[t] - my) % 2 != 0 || (outaj[t] - mx) % 2 != 0) return false;
  }
  if (My - my + 1 <= 1 || My - my + 1 != Mx - mx + 1) return false;
  memset(chk, 0, sizeof(chk));
  for (int t = 0; t < outai.size(); t++) {
    bool ch = false;
    if (outai[t] == my && outaj[t] >= mx && outaj[t] <= Mx)
      chk[0][outaj[t]] = true, ch = true;
    if (outai[t] >= my && outai[t] <= My && outaj[t] == mx)
      chk[2][outai[t]] = true, ch = true;
    if (outai[t] == My && outaj[t] >= mx && outaj[t] <= Mx)
      chk[1][outaj[t]] = true, ch = true;
    if (outai[t] >= my && outai[t] <= My && outaj[t] == Mx)
      chk[3][outai[t]] = true, ch = true;
    if (!ch) return false;
  }
  for (int x = mx; x <= Mx; x += 2)
    if (!chk[0][x] || !chk[1][x]) return false;
  for (int y = my; y <= My; y += 2)
    if (!chk[2][y] || !chk[3][y]) return false;
  return true;
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    memset(inp, 0, sizeof(inp));
    scanf("%d%d", &n, &m);
    int ret = 0;
    for (int i = 0; i < n; i++) scanf("%s", inp[i]);
    memset(cov, 0, sizeof(cov));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (inp[i][j] == '0') continue;
        if (cov[i][j]) continue;
        mx = my = 260;
        Mx = My = -1;
        outai.clear();
        outaj.clear();
        dfs(i, j);
        if (firstType()) ret++;
        if (secondType()) ret++;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
